#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t sem;

int var;
void* update(void *arg)
{
	var = *((int *)arg);
	printf("posted \n");
	sleep(10);
	sem_post(&sem);
	return NULL;
}

int get()
{
	sem_wait(&sem);
	printf("received \n");
	return var;
}

int main()
{
	int x = 10;
	pthread_t thread1;
	sem_init(&sem, 0, 0);
	pthread_create(&thread1, NULL, (void *)update, (void *)&x);
	printf(" var %d \n", get());
}
