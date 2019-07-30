//
// © Copyright 2017-2018 Hewlett Packard Enterprise Development LP
// All Rights Reserved
//
#include "permanentobjcache.hpp"
#include "imath.hpp"
#include "perfprofilelock.hpp"

using namespace obs::hwi;

struct PermanentObjCacheAddLock {};
struct PermanentObjCacheFindLock {};

PObjectCache::PObjectCache( const uint64_t bucketCount ) :
    mCapacity( nextPowerOfTwo( bucketCount ) ),
    mAddsCtr( Counter::Make(Counter::LOCAL, "permanent-obj-cache-adds") ),
    mAlreadyExistsCtr( Counter::Make(Counter::LOCAL, "permanent-obj-exists-incache") ),
    mCacheHitsCtr( Counter::Make(Counter::LOCAL, "permanent-obj-cachehits") ),
    mEvictionsCtr( Counter::Make(Counter::LOCAL, "permanent-obj-evictions") ),
    mNodeVector( mCapacity ),
    mFreeList( mNodeVector.begin(), mNodeVector.end() ),
    mEvictionList(),
    mBuckets( mCapacity ),
    mSet( SetType::bucket_traits( &mBuckets[0], mCapacity) )
{
}

PObjectCache::~PObjectCache()
{
}

size_t PObjectCache::size() const
{
    boost::mutex::scoped_lock lock( mMutex );
    return mSet.size();
}

bool PObjectCache::empty() const
{
    boost::mutex::scoped_lock lock( mMutex );
    return mSet.empty();
}

void PObjectCache::add( const ObjectSignature& _sig )
{
    SetType::insert_commit_data icd;
    PerfProfLock<PermanentObjCacheAddLock> lock( mMutex );

    std::pair<SetType::iterator, bool> result =
        mSet.insert_check( _sig, boost::hash<ObjectSignature>(),
                NodeKeyEquality(), icd );

    Node* node = NULL;
    //Already found in cache bring it to front
    if( !result.second )
    {
        node= &(*result.first);
        EvictionList::iterator itrErase = mEvictionList.iterator_to( *node );
        mEvictionList.erase( itrErase );
        incrementAlreadyExists();
    }
    else
    {
        //LRU eviction
        if ( mFreeList.empty() )
        {
            node = &mEvictionList.front();
            mEvictionList.pop_front();

            SetType::iterator itr = mSet.iterator_to( *node );
            mSet.erase( itr );
            incrementEvictions();
        } else {
            node = &mFreeList.front();
            mFreeList.pop_front();
        }
        node->Signature = _sig;
        mSet.insert_commit( *node, icd );
        incrementAdds();
    }
    mEvictionList.push_back( *node );
}

bool PObjectCache::find( const ObjectSignature& _sig ) const
{
    PerfProfLock<PermanentObjCacheFindLock> lock( mMutex );

    SetType::const_iterator find = mSet.find( _sig, boost::hash<ObjectSignature>(), NodeKeyEquality() );

    if ( find == mSet.end() )
        return false;

    const Node& node = *find;
    EvictionList::const_iterator itMru = mEvictionList.iterator_to( node );
    mEvictionList.erase( itMru );
    mEvictionList.push_back( const_cast<Node&>( node ) );
    incrementCacheHits();

    return true;
}
