#include<boost/intrusive/list.hpp>
#include <boost/noncopyable.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/thread.hpp>
#include"job.hpp"

class OJob : public boost::noncopyable, public boost::intrusive::list_base_hook<>
{
    public:
        OJob(Job& job) : mJob(job) {}

        ~OJob() {}

        Job& getJob() { return mJob; }

    private:
        Job& mJob;
};

class JobOGroup;

class JobMgr : public boost::noncopyable
{
    public:
    JobMgr(uint32_t threadCount);
    virtual ~JobMgr() { }

    void start();
    void stop();
    void addOJob(Job& job);
    boost::mutex&  getJobMutex() { return mMutex; }

    Job* getOJob();
    private:

    typedef boost::intrusive::list<OJob> JobListType;

    size_t                        mThreadCount;
    boost::mutex                  mMutex;
    JobListType                   mJobList;
    boost::scoped_ptr<JobOGroup>  mJobGroup;
};

class JobOGroup
{
    public:
        JobOGroup(uint32_t numThreads, JobMgr& jobMgr);
        virtual ~JobOGroup() { }
        bool isRunning() { return !mExit; }

        virtual void notify() { mCond.notify_one(); }

        void start();
        void stop();

    private:
        void run(uint32_t threadId);
        bool                                    mExit;
        boost::condition_variable               mCond;
        uint32_t                                mThreadCount;
        boost::scoped_ptr<boost::thread_group>  mThreadGroup;
        JobMgr&                                 mJobMgr;
        boost::mutex&                           mMutex;
};
