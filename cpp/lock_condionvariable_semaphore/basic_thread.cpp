#include<iostream>
#include<pthread.h>

using namespace std;

void* run(void *data)
{
    int *i = static_cast<int *>(data);
    cout << " calling thread data  " << *i<< endl;
    return NULL;
}

int main()
{
    pthread_t t1;
    int i = 2;

    pthread_create(&t1, NULL, run, static_cast<void *>(&i));


    pthread_join(t1, NULL); 

    return 0;
}
