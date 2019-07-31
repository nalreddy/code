#pragma once
#include <boost/noncopyable.hpp>
#include <boost/container/vector.hpp>


class DigestCache : public boost::noncopyable
{
    public:

        DigestCache(size_t _capacity);
        virtual ~DigestCache() {};

        size_t numDigestCacheCollisions() const
        {
            return mHashCollisionCount.load(boost::memory_order_relaxed);
        }
        size_t numDigestCacheAdds() const
        {
            return mCacheAddCount.load(boost::memory_order_relaxed);
        }
        size_t numDigestCacheHits() const
        {
            return mCacheHitCount.load(boost::memory_order_relaxed);
        }

        virtual void add(const Digest& _sig);

        virtual bool find(const Digest& _sig) const;

        size_t getCapacity() const;
        bool empty() const;
        size_t getSize() const;

    private:
        typedef boost::container::vector<Digest> HashTable;

        size_t getIndex(const Digest& _sig) const;

        size_t                          mCapacity;
        boost::atomic<size_t>           mHashCollisionCount;
        boost::atomic<size_t>           mCacheAddCount;
        mutable boost::atomic<size_t>   mCacheHitCount;
        size_t             mHashCollisionCtr;
        atomic           mAddsCtr;
    atmoic       mCacheHitsCtr;
        mutable svt::shared_mutex       mMutex;
        HashTable                       mHashTable;
};

