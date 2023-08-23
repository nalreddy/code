#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
#include <signal.h>
//#include <unistd.h>
#include <stddef.h>


#if 0
union sigval {            /* Data passed with notification */
		int     sival_int;    /* Integer value */
		void   *sival_ptr;    /* Pointer value */
};

struct sigevent {
		int    sigev_notify;  /* Notification method */
		int    sigev_signo;   /* Notification signal */
		union sigval sigev_value;
		/* Data passed with notification */
		void (*sigev_notify_function)(union sigval);
		/* Function used for thread
		   notification (SIGEV_THREAD) */
		void  *sigev_notify_attributes;
		/* Attributes for notification thread
		   (SIGEV_THREAD) */
		int  sigev_notify_thread_id;
		/* ID of thread to signal
		   (SIGEV_THREAD_ID); Linux-specific */
};


union X
{
	int i;
	void *ptr;
};


struct A
{
	int a; 
	union X val;
	double c;
};

#endif
int main()
{
	struct sigevent sev;
	
//	printf("segevent size %d offet of ptr %d \n", sizeof(struct A),  offsetof(struct A, val ));
	//printf("segevent size %d offet of ptr %d \n", sizeof(struct sigevent),  offsetof(struct sigevent, sigev_signo ));
	printf("segevent size %d offet of ptr %d \n", sizeof(struct sigevent),  offsetof(struct sigevent, sigev_value ));
	//printf("segevent size %d offet of ptr %d \n", sizeof(struct sigevent),  offsetof(struct sigevent, sigev_value.sival_int ));
}
