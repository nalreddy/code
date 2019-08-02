#include<iostream>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#include"data.hpp"


pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
bool run = false;

void* producer(void *ptr)
{
    Store* st = (Store*) ptr;
    srand(0);

    while(1)
    {
        std::cout << " producer " << std::endl;
        pthread_mutex_lock(&lock);
#if 0
        if (run)
            //wait

            st.put(rand());
        run = true;
#endif
        st->put(rand());
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&cond1);
        std::cout << " producer end" << std::endl;
        sleep(1);
    }
}

void* consumer(void* ptr)
{
    Store* st = (Store*) ptr;
    while(1)
    {
        std::cout << " consumer" << std::endl;
        pthread_mutex_lock(&lock);
        if(st->empty())
        {
            std::cout << " consumer waiting list empty" << std::endl;
            pthread_cond_wait(&cond1, &lock);
        }
        std::cout << st->get() << std::endl;
        pthread_mutex_unlock(&lock);
        std::cout << " consumer end" << std::endl;
        sleep(1);
    }
}


int main()
{
    Store* st = new Store();

    for(size_t i = 0; i < 10; i++)
        st->put(i);

    st->show();

    for(size_t i = 0; i < 10; i++)
        std::cout << st->get() << std::endl;

    pthread_t tid1, tid2;

    // Create thread 2
    pthread_create(&tid2, NULL, consumer, st);

    // Create thread 1
    pthread_create(&tid1, NULL, producer, st);

    // wait for the completion of thread 2
    pthread_join(tid2, NULL);
    pthread_join(tid1, NULL);

    delete st;

    return 0;
}

