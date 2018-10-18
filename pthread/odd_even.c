#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

int count = 0;

#define MAX 15

void* odd()
{
    while (count < MAX) {

        pthread_mutex_lock(&count_mutex);
        if ((count % 2 ) == 0) {
            pthread_cond_wait(&condition_var, &count_mutex);
        }
        printf(" odd count = %d \n", count);
        count++;
        pthread_mutex_unlock( &count_mutex );
        pthread_cond_signal( &condition_var );
    }
}

void* even()
{
    while (count < MAX) {

        pthread_mutex_lock(&count_mutex);
        if ((count % 2 ) != 0) {
            pthread_cond_wait(&condition_var, &count_mutex);
        }
        printf("Evencount = %d \n", count);
        count++;
        pthread_mutex_unlock( &count_mutex );
        pthread_cond_signal( &condition_var );
    }
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, &odd, NULL);
    pthread_create(&thread1, NULL, &even, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
