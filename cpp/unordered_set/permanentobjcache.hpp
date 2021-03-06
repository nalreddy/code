//
// © Copyright 2017-2018 Hewlett Packard Enterprise Development LP
// All Rights Reserved
//
#pragma once
#include <boost/noncopyable.hpp>
#include <boost/intrusive/list.hpp>
#include <boost/intrusive/slist.hpp>
#include <boost/intrusive/unordered_set.hpp>
#include <boost/thread/mutex.hpp>
#include "objsig.hpp"
#include "counter.hpp"

namespace obs
{
namespace hwi
{
class PObjectCache : public boost::noncopyable
{
    public:

        PObjectCache( const uint64_t bucketCount );
        virtual ~PObjectCache();

        uint64_t numPObjectAdds() const { return mAddsCtr->value(); }
        void incrementAdds() { ++mAddsCtr; }
        uint64_t numPObjectAlreadyExists() const { return mAlreadyExistsCtr->value(); }
        void incrementAlreadyExists() { ++mAlreadyExistsCtr; }
        uint64_t numPObjectCacheHits() const { return mCacheHitsCtr->value(); }
        void incrementCacheHits() const { ++mCacheHitsCtr; }
        uint64_t numPObjectEvictions() const { return mEvictionsCtr->value(); }
        void incrementEvictions() { ++mEvictionsCtr; }

        virtual void add( const ObjectSignature& _sig );
        virtual bool find( const ObjectSignature& _sig ) const;

        inline size_t capacity() const { return mCapacity; }
        size_t size() const;
        bool empty() const;

    protected:

        struct Node
        {
            ObjectSignature  Signature;
            boost::intrusive::unordered_set_member_hook<> SetHook;
            boost::intrusive::list_member_hook<>          ListHook;
        };

    private:

        friend size_t hash_value( const Node& _node );
        friend bool operator==( const Node& _l, const Node& _r );

        struct NodeKeyEquality
        {
            inline bool operator()( const ObjectSignature& _sig, const Node& _node) const
            {
                return _sig == _node.Signature;
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
        Counter::Ptr             mAddsCtr;
        Counter::Ptr             mAlreadyExistsCtr;
        mutable Counter::Ptr     mCacheHitsCtr;
        Counter::Ptr             mEvictionsCtr;
        std::vector<Node>        mNodeVector;
        FreeList                 mFreeList;
        mutable EvictionList     mEvictionList;
        BucketVector             mBuckets;
        SetType                  mSet;
        mutable boost::mutex     mMutex;
};

inline size_t hash_value( const PObjectCache::Node& _node )
{
    return hash_value( _node.Signature );
}

inline bool operator==( const PObjectCache::Node& _l, const PObjectCache::Node& _r )
{
    return _l.Signature == _r.Signature;
}

}
}
