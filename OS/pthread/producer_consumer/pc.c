#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
typedef int buffer_item;
#define BUFFER_SIZE 5

#define RAND_DIVISOR 100000000
#define TRUE 1

pthread_mutex_t mutex;

sem_t full, empty;

buffer_item buffer[BUFFER_SIZE];

int counter;

pthread_t tid;      
pthread_attr_t attr; 

void *producer(void *param); 
void *consumer(void *param); 

int insert_item(buffer_item item) {

	if(counter < BUFFER_SIZE) {
		buffer[counter] = item;
		counter++;
		return 0;
	}
	else { 
		return -1;
	}
}

int remove_item(buffer_item *item) {
	if(counter > 0) {
		*item = buffer[(counter-1)];
		counter--;
		return 0;
	}
	else {
		return -1;
	}
}

void initializeData() {

	pthread_mutex_init(&mutex, NULL);

	sem_init(&full, 0, 0);

	sem_init(&empty, 0, BUFFER_SIZE);

	pthread_attr_init(&attr);

	counter = 0;
}

void *producer(void *param) {
	buffer_item item;

	while(TRUE) {
		int rNum = rand() / RAND_DIVISOR;
		sleep(1);

		item = rand()%100;

		sem_wait(&empty);
		pthread_mutex_lock(&mutex);

		if(insert_item(item)) {
			fprintf(stderr, " Producer report error condition\n");
		}
		else {
			printf("producer produced %d\n", item);
		}
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}

void *consumer(void *param) {
	buffer_item item;
	int* consumerID=(int*)param;

	while(TRUE) {
		int rNum = rand() / RAND_DIVISOR;
		sleep(1);

		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		if(remove_item(&item)) {
			fprintf(stderr, "Consumer report error condition\n");
		}
		else {
			printf("consumer %d consumed %d\n" ,*consumerID, item);

		}
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

int main(int argc, char *argv[]) {
	int i;

	int numProd = 1;
	int numCons = 1;

	initializeData();

	for(i = 0; i < numProd; i++) {
		pthread_create(&tid, &attr, producer,NULL);
	}

	for(i = 0; i < numCons; i++) {
		pthread_create(&tid, &attr, consumer, (void*)&i);
	}

	pthread_join(

	printf("Exit the program\n");
	exit(0);
}
