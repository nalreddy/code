#include<iostream>
#include<pthread.h>

using namespace std;

#define INV -1
int i_shared = 0;
const int target = 25;
const int critical = 28;
const int max = 30;


// Declaration of thread condition variable 
pthread_cond_t con_var = PTHREAD_COND_INITIALIZER; 
pthread_cond_t proc_var = PTHREAD_COND_INITIALIZER; 
// Declaring mutex 
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 

void*
producer(void *data)
{
    int* i = static_cast<int*>(data);

    cout << " producer i = " << *i << endl;
    while (1) {

        pthread_mutex_lock(&lock); 

        while (i_shared >= critical)  {
            cout << "producer i  waiting for consumer data  " << *i << "  " << i_shared  << endl;
            pthread_cond_wait(&proc_var, &lock);
            cout << "producer i signaled by  consumer " << *i << "  " << i_shared << endl;
        }
        bool was_zero = i_shared == 0 ? 1 : 0;

        if (i_shared < target) {
            i_shared += 2;
            sleep(1);
        } else {
            i_shared++;
            sleep(2);
        }
        cout << " producer i  data  " << *i <<  "    "  << i_shared << endl;

        if (was_zero) { 
            cout << "producer i signaled  consumer " << *i << "  " << i_shared << endl;
            pthread_cond_signal(&con_var); 
         }

        pthread_mutex_unlock(&lock); 
    }

    return NULL;
}

void* consumer(void *data)
{


    while (1) {

        cout << "consumer " << endl;
        pthread_mutex_lock(&lock); 


        while (i_shared == 0) {
            cout << "consumer waiting for producers " << endl;
            pthread_cond_wait(&con_var, &lock);
            cout << "consmuer signaled by producer " << i_shared << endl;
        }

        bool was_critical = i_shared >= critical ? 1 : 0;

        cout << " consumer data " << i_shared << endl;

        if (i_shared >= critical)
            i_shared -= 2;
        else 
            i_shared--;

        if (was_critical) {
            cout << "consumer singaling procuders , under thresold  " << i_shared << endl;
            pthread_cond_broadcast(&proc_var);
       //     pthread_cond_signal(&proc_var); 
        }

        pthread_mutex_unlock(&lock); 
    }

    return NULL;
}

int main()
{
    pthread_t prod[10];
    pthread_t con;

    for (int i = 0; i < 10; i++) {
        pthread_create(&prod[i] , NULL, producer, static_cast<void *>(&prod[i]));
    }
    pthread_create(&con, NULL, consumer, NULL);


    for (int i = 0; i < 10; i++)
        pthread_join(prod[i], NULL); 
    pthread_join(con, NULL); 

    return 0;
}
