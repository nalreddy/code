class OJob : public boost::noncopyable,
    public boost::intrusive::list_base_hook<>
{
    public:
        OJob(Job& job) : mJob(job) {}

        ~OJob() {}

        void* operator new(size_t size);

        void operator delete(void* ptr)
        {
            //  .free(ptr);
        }

    private:
        Job& mJob;
};

class JobMgr
{
    addOJob(Job& job)
    {
        OJob* oJob = new OJob(job);

        boost::mutex::scoped_lock lock(mutex);

        if (mOGroup && mOGroup->Running())
        {
            mJobList.push_back(*offloadedJob);

            mOGroup->notify();
        }
    }

    Job* getOJob()
    {
        boost::mutex::scoped_lock lock(mutex);
        OffloadedJobListType::iterator iter = mJobList.begin();

        if (iter != mJobList.end()) {
            OJob& ojob= *iter;
            mJobList.erase(mJobList.iterator_to(ojob));
            Job& job = oJob.getJob();
            delete &offloadedJob;
            return &job;
        } else {
            return NULL;
        }
    }
    private:

    typedef boost::intrusive::list<OJob>   JobListType;
    iJobListType                               mJobList;
    boost::scoped_ptr<JobOGroup> mOGroup;


}

class JobOGroup
{

    public:
        JobOGroup(
                uint32_t numThreads);

        virtual ~JobOGroup();

        void start();
        void stop();
        bool Running() { return !mExit; }

        virtual void notify() { mCond.notify_one(); }

    private:
        void run(uint32_t threadId);

        bool                                    mExit;
        boost::mutex&                           mMutex;
        boost::condition_variable               mCond;
        uint32_t                                mThreadCount;
        boost::scoped_ptr<boost::thread_group>  mThreadGroup;
};

    void
start()
{
    mThreadGroup.reset(new boost::thread_group);
    for (uint32_t i = 0; i < mThreadCount; ++i) {
        mThreadGroup->create_thread(boost::bind(&oup::run, boost::ref(*this), i));         }
}

    void
stop()
{
    {
        boost::mutex::scoped_lock lock(mutex);
        if (! mThreadGroup) {
            return;
        }
        mExit = true;
        mCond.notify_all();
    }
    mThreadGroup->join_all();
    mThreadGroup.reset();
}

run(uint32_t threadId)
{
    Job* job = NULL;

    while (!mExit)
    {
        {
            boost::mutex::scoped_lock lock(mutex);
            while (((job = mManager.getOjob()) == NULL) && !mExit) {
                mCond.wait(lock);
            }
        }

        if (job) {
            Job::SubOpcodeType nextSubJob = job->getCurSubJob();
            job->doSubJob(nextSubJob); }
    }

    while ((job = mMGR.getOJob()))
    {
        Job::SubkOpcodeType nextSubJob = job->getCurrentSubJob();
        job->doSubJob(nextSubJob);
    }

}

