#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define NUM_THREADS 5
#define BUF_LEN 5
#define MAX_ITEMS 2 

int buf[BUF_LEN] = {0};
int in = 0;
int out = 0;

pthread_mutex_t lock;
sem_t empty;
sem_t full;

void* producer(void *input)
{
	int tid = *((int*) input);
	for(int i = 0; i < MAX_ITEMS; i++) {
		sem_wait(&empty);
		pthread_mutex_lock(&lock);
		int item = rand();
		printf("Producer Thread number %d item %d @ in %d \n", tid, item, in);
		buf[in] = item;
		in = (in + 1) % BUF_LEN;
		pthread_mutex_unlock(&lock);
		sem_post(&full);
	}
}
void* consumer(void *input)
{
	int tid = *((int*) input);

	for(int i = 0; i < MAX_ITEMS; i++) {
		sem_wait(&full);
		pthread_mutex_lock(&lock);

		int item = buf[out];
		printf("Consumer Thread number %d item %d @ %d\n", tid, item, out);
		out = (out + 1) % BUF_LEN;
		pthread_mutex_unlock(&lock);
		sem_post(&empty);
	}
}

int main() {
	pthread_t prod[NUM_THREADS], con[NUM_THREADS];
	int err;

	pthread_mutex_init(&lock, NULL);
	sem_init(&empty, 0, BUF_LEN);
	sem_init(&full, 0, 0);

	for (int i = 0; i < NUM_THREADS; i++) {
		err = pthread_create( &prod[i], NULL, &producer, &i);
		if ( err < 0) {
			printf("Failed to create prodcuer thread %d error %d", i, err);
		}
	}

	for (int i = 0; i < NUM_THREADS; i++) {
		err = pthread_create( &con[i], NULL, &consumer, &i);
		if ( err < 0) {
			printf("Failed to create consumer thread %d error %d", i, err);
		}
	}

	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(prod[i], NULL);
		pthread_join(con[i], NULL);
	}

	return 0;
}
