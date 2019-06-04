#include<iostream>
#include<pthread.h>

using namespace std;

#define INV -1
int i_shared = 0;

bool consumed = false;

// Declaration of thread condition variable 
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER; 
// Declaring mutex 
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 

void*
producer(void *data)
{
    while (1) {

        pthread_mutex_lock(&lock); 

        while (consumed)  {
            cout << "producer waiting for consumer" << endl;
            pthread_cond_wait(&cond_var, &lock);
            cout << "producer signaled by  consumer , flag " << consumed <<  endl;
        }

        cout << " enter data" << endl;
        cin >> i_shared;

        if (i_shared == INV)  {
           cout  << " exiting producer " << endl;
           consumed = true; 
           pthread_mutex_unlock(&lock); 
           pthread_cond_signal(&cond_var); 
           return NULL;
        }

        consumed = true; 
        pthread_mutex_unlock(&lock); 
        pthread_cond_signal(&cond_var); 
    }

    return NULL;
}

void* consumer(void *data)
{
    while (1) {

        pthread_mutex_lock(&lock); 

        while (!consumed) {
            cout << "consumer waiting for producer" << endl;
            pthread_cond_wait(&cond_var, &lock);
            cout << "consmuer signaled by producer , flag  " << consumed <<  endl;
        }

        if (i_shared == INV) {
            cout << " exiting consumer " << endl;
            pthread_mutex_unlock(&lock); 
            return NULL;
        }

        cout << " consumer data " << i_shared << endl;
        consumed = false;
        pthread_mutex_unlock(&lock); 
        pthread_cond_signal(&cond_var); 
    }

    return NULL;
}

int main()
{
    pthread_t prod;
    pthread_t con;

    pthread_create(&con, NULL, consumer, NULL);//static_cast<void *>(&i));
    pthread_create(&prod, NULL, producer, NULL);//static_cast<void *>(&i));


    pthread_join(prod, NULL); 
    pthread_join(con, NULL); 

    return 0;
}
