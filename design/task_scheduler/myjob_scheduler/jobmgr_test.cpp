#include<iostream>
#include<chrono>
#include<thread>
#include"jobmgr.hpp"

int main()
{
    using namespace std::chrono_literals;
    Job *j1 = new Job(5,2);


    for(int jop = 0; jop < MAX; jop++)
    {
        j1->addSubJob(static_cast<JobOpCode>(jop));
    }


    JobMgr* jmgr = new JobMgr(1);

    jmgr->start();
    jmgr->addOJob(*j1);

    std::this_thread::sleep_for(20s);

    delete jmgr;

    return 0;
}
