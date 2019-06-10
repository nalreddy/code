
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

class Examplae
{
//example
void Thread()
   {
           thread::set_name(boost::str(boost::format("hdl-%1%") % mName));

               while (true)
               {
                   Completion* ioc = NULL;
                   {
                    boost::mutex::scoped_lock lock(mMutex);

                        while (!mExit && mCompletionQueue.empty())
                            mCond.wait(lock);

                        if (mExit)
                            break;

                    ioc = &mCompletionQueue.front();
                    mCompletionQueue.pop_front();
                }
                   ioc->notify();
               }
   }

boost::mutex                mMutex;
boost::condition_variable   mCond;
bool                        mExit;
CompletionList            mCompletionQueue;
boost::thread               mCompletionThread;

};
