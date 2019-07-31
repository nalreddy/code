
DigestCache::DigestCache( const uint64_t bucketCount ) :
    mCapacity( nextPowerOfTwo( bucketCount ) ),
    mAddsCtr,
    mAlreadyExistsCtr,
    mCacheHitsCtr,
    mEvictionsCtr,
    mNodeVector( mCapacity ),
    mFreeList( mNodeVector.begin(), mNodeVector.end() ),
    mEvictionList(),
    mBuckets( mCapacity ),
    mSet( SetType::bucket_traits( &mBuckets[0], mCapacity) )
{
}

DigestCache::~DigestCache()
{
}

size_t DigestCache::size() const
{
    boost::mutex::scoped_lock lock( mMutex );
    return mSet.size();
}

bool DigestCache::empty() const
{
    boost::mutex::scoped_lock lock( mMutex );
    return mSet.empty();
}

void DigestCache::add( const Digest& _sig )
{
    SetType::insert_commit_data icd;
    mutex lock( mMutex );

    std::pair<SetType::iterator, bool> result =
        mSet.insert_check( _sig, boost::hash<Digest>(),
                NodeKeyEquality(), icd );

    Node* node = NULL;
    //Already found in cache bring it to front
    if( !result.second )
    {
        node= &(*result.first);
        EvictionList::iterator vItrErase = mEvictionList.iterator_to( *node );
        mEvictionList.erase( vItrErase );
        incrementAlreadyExists();
    }
    else
    {
        //LRU eviction
        if ( mFreeList.empty() )
        {
            node = &mEvictionList.front();
            mEvictionList.pop_front();

            SetType::iterator vItr = mSet.iterator_to( *node );
            mSet.erase( vItr );
            incrementEvictions();
        } else {
            node = &mFreeList.front();
            mFreeList.pop_front();
        }
        node->Digest = _sig;
        mSet.insert_commit( *node, icd );
        incrementAdds();
    }
    mEvictionList.push_back( *node );
}

bool DigestCache::find( const Digest& _sig ) const
{
    mutex lock( mMutex );

    SetType::const_iterator vFind = mSet.find( _sig, boost::hash<Digest>(), NodeKeyEquality() );

    if ( vFind == mSet.end() )
        return false;

    const Node& node = *vFind;
    EvictionList::const_iterator itMru = mEvictionList.iterator_to( node );
    mEvictionList.erase( itMru );
    mEvictionList.push_back( const_cast<Node&>( node ) );
    incrementCacheHits();

    return true;
}
