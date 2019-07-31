#pragma once
#include <boost/noncopyable.hpp>
#include <boost/intrusive/list.hpp>
#include <boost/intrusive/slist.hpp>
#include <boost/intrusive/unordered_set.hpp>
#include <boost/thread/mutex.hpp>

class DigestCache : public boost::noncopyable
{
    public:

        DigestCache( const uint64_t bucketCount );
        virtual ~DigestCache();

        uint64_t numDigestAdds() const { return mAddsCtr->value(); }
        void incrementAdds() { ++mAddsCtr; }
        uint64_t numDigestAlreadyExists() const { return mAlreadyExistsCtr->value(); }
        void incrementAlreadyExists() { ++mAlreadyExistsCtr; }
        uint64_t numDigestCacheHits() const { return mCacheHitsCtr->value(); }
        void incrementCacheHits() const { ++mCacheHitsCtr; }
        uint64_t numDigestEvictions() const { return mEvictionsCtr->value(); }
        void incrementEvictions() { ++mEvictionsCtr; }

        virtual void add( const ODigest& _sig );
        virtual bool find( const ODigest& _sig ) const;

        inline size_t capacity() const { return mCapacity; }
        size_t size() const;
        bool empty() const;

    protected:

        struct Node
        {
            ODigest  Digest;
            boost::intrusive::unordered_set_member_hook<> SetHook;
            boost::intrusive::list_member_hook<>          ListHook;
        };

    private:

        friend size_t hash_value( const Node& _node );
        friend bool operator==( const Node& _l, const Node& _r );

        struct NodeKeyEquality
        {
            inline bool operator()( const ODigest& _sig, const Node& _node) const
            {
                return _sig == _node.Digest;
            }
        };

        typedef boost::intrusive::member_hook<
            Node,
            boost::intrusive::unordered_set_member_hook<>,
            &Node::SetHook
        > SetHookType;

        typedef boost::intrusive::member_hook<
            Node,
            boost::intrusive::list_member_hook<>,
            &Node::ListHook
        > ListHookType;

        typedef boost::intrusive::slist<Node, SetHookType> FreeList;
        typedef boost::intrusive::list<Node, ListHookType> EvictionList;

        typedef boost::intrusive::unordered_set<
            Node,
            SetHookType,
            boost::intrusive::equal<std::equal_to<Node> >,
            boost::intrusive::hash<boost::hash<Node> >,
            boost::intrusive::constant_time_size<false>,
            boost::intrusive::power_2_buckets<true>  // NOTE: value of false may have performance implications.
        > SetType;

        typedef std::vector<SetType::bucket_type> BucketVector;

        size_t                   mCapacity;
                     mAddsCtr;
        atomic_t             mAlreadyExistsCtr;
        mutable size_t     mCacheHitsCtr;
                     mEvictionsCtr;
        std::vector<Node>        mNodeVector;
        FreeList                 mFreeList;
        mutable EvictionList     mEvictionList;
        BucketVector             mBuckets;
        SetType                  mSet;
        //can be share lock for find i.e readers
        mutable boost::mutex     mMutex;
};

inline size_t hash_value( const DigestCache::Node& _node )
{
    return hash_value( _node.Digest );
}

inline bool operator==( const DigestCache::Node& _l, const DigestCache::Node& _r )
{
    return _l.Digest == _r.Digest;
}

}
}
