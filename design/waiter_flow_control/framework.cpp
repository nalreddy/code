void* alloc()
{
    void* buf;

    buf = MemPool::alloc();
    if (buf) {
        return buf;
    }

    boost::mutex::scoped_lock lock(mMutex);
    while ((buf = MemPool::alloc()) == NULL)
    {
        ++mWaiters;
        mCond.wait(lock);
        --mWaiters;
    }

    return buf;
}

void free(void* buf)
{
   MemPool::free(buf);

    boost::mutex::scoped_lock lock(mMutex);
    if (mWaiters) {
        mCond.notify_one();
    }
}

private:
uint64_t                    mWaiters;
boost::mutex                mMutex;
boost::condition_variable   mCond;


