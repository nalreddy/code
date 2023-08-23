#include<stdio.h>
#include<stdatomic.h>
#include<sys/time.h> 
#include<stdbool.h>
#include<pthread.h>
#include<unistd.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

struct rate_limiter
{
	int bucket_capacity;
	int refresh_rate;
	atomic_int current_capacity;
	struct timeval last_updated;	
};

struct rate_limiter rt;


unsigned long seconds_elapsed(struct timeval *start, struct timeval *end)
{
	unsigned long seconds;

	seconds = (end->tv_sec - start->tv_sec) * 1000UL * 1000;
	seconds += end->tv_usec - start->tv_usec;
	seconds /= 1000 * 1000;

	return seconds;
}

unsigned long milliseconds_elapsed(struct timeval *start, struct timeval *end)
{
		unsigned long milliseconds;

		milliseconds = (end->tv_sec - start->tv_sec) * 1000UL;
		milliseconds += (end->tv_usec - start->tv_usec) / 1000;

		return milliseconds;
}

void init_bucket(int capacity)
{
	gettimeofday(&rt.last_updated, NULL);
	rt.bucket_capacity = capacity;
	rt.refresh_rate = 0.5;
	rt.current_capacity = capacity;
}

void refresh_bucket()
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);

	//int additional_tokens = (int) (seconds_elapsed(rt.last_updated , current_time)/1000 * refresh_rate);
	int additional_tokens = (int) (seconds_elapsed(&rt.last_updated , &current_time) * rt.refresh_rate);
	printf("additional tokens %d \n", additional_tokens);
	rt.current_capacity = MIN((rt.current_capacity + additional_tokens), rt.bucket_capacity);
}

bool grant()
{
	refresh_bucket();

	if (rt.current_capacity > 0)
	{
		rt.current_capacity--;
		return true;
	}

	return false;
}


void* print(void *arg)
{
	int x = 1;
	while(true)
	{
		if(grant())
		{
			printf("x = %d\n",x);
			x++;
		} else {
			printf("bucket full requeue \n");
			sleep(1);
		}
	}
}

int main()
{
	pthread_t pid[10];

	init_bucket(5);

	for(int i = 0; i < 100; i++)
			pthread_create(&pid[i], NULL, print, NULL);
	while(1) {}
	return 0;
}
