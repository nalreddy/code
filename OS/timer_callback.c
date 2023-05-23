#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <stddef.h>

void expired(union sigval timer_data);
void start_timer();

pid_t gettid(void);

#if 0
timer_t timerId = 0;
struct sigevent sev = { 
			    .sigev_notify = SIGEV_THREAD,
                .sigev_notify_function = &expired,
                .sigev_value.sival_ptr = &timerId,
			};
#endif
struct itimerspec its = {   .it_value.tv_sec  = 1,
		.it_value.tv_nsec = 0,
		.it_interval.tv_sec  = 0,
		.it_interval.tv_nsec = 0
};

void* thread_function(void *data)
{
	printf(" start work \n");
	start_timer();
	return NULL;
}

struct A
{
	struct sigevent sev;
	timer_t timerId;
};

void start_timer()
{
//	timer_t *timerId = (timer_t*) malloc(sizeof(timer_t));
	struct A *a = (struct A*) malloc(sizeof(struct A));

	memset(a, 0, sizeof(struct A));
	//struct sigevent *sev = (struct sigevent *)malloc(sizeof (struct sigevent));

//	printf("sev %p \n", sev);
//i	printf("timer %p \n", timerId);
	a->sev.sigev_notify = SIGEV_THREAD;
	a->sev.sigev_notify_function = &expired;
	a->sev.sigev_value.sival_ptr = a;
	int res;	
    /* create timer */
    res = timer_create(CLOCK_REALTIME, &a->sev, &a->timerId);
    if (res != 0){
        fprintf(stderr, "Error timer_create: %s\n", strerror(errno));
        exit(-1);
    }

    /* start timer */
    res = timer_settime(a->timerId, 0, &its, NULL);
    if (res != 0){
		timer_delete(a->timerId);
		free(a);
        fprintf(stderr, "Error timer_settime: %s\n", strerror(errno));
        exit(-1);
    }
	printf("timer started \n");
}

int main()
{
    int res = 0;
	pthread_t t1;


//	for (int i = 0; i < 10 ; i++)
	pthread_create (&t1,NULL,thread_function,NULL);

    printf("Press ETNER Key to Exit\n");
    while(getchar()!='\n'){}
    return 0;
}


void expired(union sigval timer_data){
	struct A *a = (struct A*) timer_data.sival_ptr;

	timer_t timerId = a->timerId;
//	struct sigevent sev = a->sev;	
//    timer_t *timerId = (timer_t *)timer_data.sival_ptr;

  //  struct sigevent *sev =  (struct sigevent *)( (char *)timerId - offsetof(struct sigevent, sigev_value ));

//	printf("seg size %d offet %d \n", sizeof(struct sigevent),  offsetof(struct sigevent, sigev_value ));
//	printf("sev in call back %p\n", sev);
	printf("timer in call back %p\n", timerId);
    //int *data = timer_data.sival_ptr;
//	printf("timer data  %d\n", *data);
//    printf("Done Timer fired %d - thread-id: %d\n", ++data->myData, gettid());
	printf("timer experied \n");
	timer_delete(timerId);
//	free(timerId);
	free(a);
}
