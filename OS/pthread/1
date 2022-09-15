#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include <linux/unistd.h>


void *print(void  *x) {

    int *i = (int *)x;
    printf("from thread pid %d ppid %d \n",getpid(), getppid());
    printf("x = %d\n",*i);
    printf("TGID(%d), PID(%d), pthread_self(%d) : Child \n", getpid(), syscall(__NR_gettid), pthread_self());
    while (1) {}
    return NULL;
}

int main()
{
    pthread_t pid[1];

    int x = 10;
    int i = 0;

    printf("from main pid %d ppid %d \n",getpid(), getppid());
    for(i = 0; i < 1; i++) {

        if(pthread_create(&pid[i], NULL,print,&i))
            printf("failed to create \n");
    }

    for(i = 0; i < 1; i++) 
        pthread_join(pid[i], NULL);

    return 0;
}
