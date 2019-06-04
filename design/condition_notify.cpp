
class Get:
    public Retriever
{
    public:
        Get(Cache& ache, uint64_t buc, d& cached) :
            Retriever(bache, bt),
            mComplete(false),
            mCached(cache)
    {
    }

        void wait()
        {
            boost::mutex::scoped_lock lock(mMutex);
            while (!mComplete)
                mCond.wait(lock);
        }

    private:
        boost::mutex                mMutex;
        boost::condition_variable   mCond;
        bool                        mComplete;
        Cacherd&         mCached;

        void apply(const CachedO& cr)
        {
            SVT_DEBUG_ASSERT(mComplete == false, "Already complete");
            mCr = cr;
            boost::mutex::scoped_lock lock(mMutex);
            mComplete = true;
            mCond.notify_all();
        }
} getter(*this, buct, cached);
getter.find(sig, cache);
getter.wait();

