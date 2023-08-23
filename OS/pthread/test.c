#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int count = 0;

#define MAX 10


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* odd(void* arg)
{
	while(count < MAX)
	{
		pthread_mutex_lock(&mutex);
		if (count % 2 == 0)
		pthread_cond_wait(&cond, &mutex);

		printf("odd %d \n", count); 
		count++;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
	}
}

void* even(void* arg)
{
	while(count < MAX)
	{
		pthread_mutex_lock(&mutex);
		if (count % 2 != 0)
		pthread_cond_wait(&cond, &mutex);

		printf("even %d \n", count); 

		count++;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, odd, NULL);
	pthread_create(&t2, NULL, even, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
