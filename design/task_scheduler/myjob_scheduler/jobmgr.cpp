#include <boost/function.hpp>
#include"jobmgr.hpp"

JobOGroup::JobOGroup(uint32_t numThreads, JobMgr& jobMgr) :
    mExit(false),
    mThreadCount(numThreads),
    mJobMgr(jobMgr),
    mMutex(mJobMgr.getJobMutex())
{
}

void JobOGroup::start()
{
    std::cout << " JobOgroup started " << std::endl;
    mThreadGroup.reset(new boost::thread_group);
    for (uint32_t i = 0; i < mThreadCount; ++i) {
        mThreadGroup->create_thread(boost::bind(&JobOGroup::run, boost::ref(*this), i));
    }
}

void JobOGroup::stop()
{
    {
        boost::mutex::scoped_lock lock(mMutex);
        if (!mThreadGroup) {
            return;
        }
        mExit = true;
        mCond.notify_all();
    }
    mThreadGroup->join_all();
    mThreadGroup.reset();
}

void JobOGroup::run(uint32_t threadId)
{
    Job* job = NULL;

    std::cout<< " group run >" << std::endl;
    while (!mExit)
    {
        std::cout << "entrt while " << std::endl;
        {
            boost::mutex::scoped_lock lock(mMutex);
            while (((job = mJobMgr.getOJob()) == NULL) && !mExit) {
                std::cout << " waiting for job"<< std::endl;
                mCond.wait(lock);
            }
        }

        if (job) {
            JobOpCode nextSubJob = job->getSubJob();
            std::cout << " Got the Job" << nextSubJob << std::endl;
            job->doSubTask(nextSubJob);
            if (nextSubJob < MAX)
                mJobMgr.addOJob(*job);
            std::cout << " Got the Job" << std::endl;
        }
    }
#if 0
            while ((job = mJobMgr.getOJob()))
            {
                JobOpCode nextSubJob = job->getSubJob();
                job->doSubTask(nextSubJob);
                std::cout << " job found " << std::endl;
            }

#endif
}

JobMgr::JobMgr(uint32_t threadCount):
    mThreadCount(threadCount),
    mJobGroup()
{
}

void JobMgr::start()
{
    mJobGroup.reset(new JobOGroup(mThreadCount, *this));
    mJobGroup->start();
}

void JobMgr::stop()
{
    if (mJobGroup != NULL) {
        mJobGroup->stop();
        boost::mutex::scoped_lock lock(mMutex);
        mJobGroup.reset();
    }
}

void JobMgr:: addOJob(Job& job)
{
    OJob* oJob = new OJob(job);

    boost::mutex::scoped_lock lock(mMutex);

    if (mJobGroup && mJobGroup->isRunning())
    {
        mJobList.push_back(*oJob);
        std::cout << "added to  list " << std::endl;
        mJobGroup->notify();
    } else
    {
        mJobList.push_back(*oJob);
    }
}

Job* JobMgr::getOJob()
{
    //boost::mutex::scoped_lock lock(mMutex);
    JobListType::iterator iter = mJobList.begin();

    if (iter != mJobList.end()) {
        OJob& oJob = *iter;
        mJobList.erase(mJobList.iterator_to(oJob));
        Job& job = oJob.getJob();
        delete &oJob;
        std::cout << " getOjob" << std::endl;
        return &job;
    } else {
        std::cout << " getOjob NULL" << std::endl;
        return NULL;
    }
}

