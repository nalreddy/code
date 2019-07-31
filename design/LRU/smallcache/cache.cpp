#include <boost/bind.hpp>
#include <boost/functional/hash.hpp>

inline void Increment(boost::atomic<size_t>& _val)
{
    const size_t prev = _val.load(boost::memory_order_relaxed);
    _val.store(std::plus<size_t>()(prev, 1), boost::memory_order_relaxed);
}
DigestCache::DigestCache(size_t _capacity) :
    mCapacity(_capacity),
    mHashCollisionCount(0),
    mCacheAddCount(0),
    mCacheHitCount(0),
    mMutex()
{

    mHashTable.reserve(mCapacity);
    for (size_t i = 0; i < mCapacity; i++)
    {
        mHashTable.emplace_back(Digest);    }
}

size_t DigestCache::getIndex(const Digest& _dig) const
{
    return (boost::hash<Digest>()(_dig)) % mCapacity;
}

void DigestCache::add(const Digest& _dig)
{
    size_t idx = getIndex(_dig);
    const Digest& dig = mHashTable[idx];

   shared_mutex uniqueLock(mMutex);
    if (dig.isValid() && (dig == _dig))
    {
        return;
    }

    if (dig.isValid() && !(dig == _dig))
    {
        protectedIncrement(mHashCollisionCount);
    }

    mHashTable[idx] = _dig;
    protectedIncrement(mCacheAddCount);
}

bool DigestCache::find(const Digest& _dig) const
{
    size_t idx = getIndex(_dig);
    const Digest& dig = mHashTable[idx];

    false negatives,testing without taking shared lock
    if (!(dig.isValid() && (dig == _dig)))
    {
        return false;
    }

    shared_mutex, boost::shared_lock sharedLock(mMutex);
    if (dig.isValid() && (dig == _dig))
    {
        Increment(mCacheHitCount);
        return true;
    }
    return false;
}

size_t DigestCache::getCapacity() const
{
    return mCapacity;
}

bool DigestCache::empty() const
{
    boost::unique_lock<shared_mutex> uniqueLock(mMutex);
    return (0 == numDigestCacheAdds());
}

size_t DigestCache::getSize() const
{
    boost::unique_lock<shared_mutex> uniqueLock(mMutex);
    return (numDigestCacheAdds() - numDigestCacheCollisions());
}
