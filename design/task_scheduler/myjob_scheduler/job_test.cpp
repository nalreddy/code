#include<iostream>
#include "job.hpp"

using namespace std;

int main()
{
    Job* j1 = new Job(5,2);

    for(int jop = 0; jop < MAX; jop++)
    {
        j1->addSubJob(static_cast<JobOpCode>(jop));
    }

    for(int jop = 0; jop < MAX; jop++)
    {
        j1->doSubTask(j1->getSubJob());
    }

    delete j1;
    return 0;
}


