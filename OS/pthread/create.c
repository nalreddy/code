#include<stdio.h>
#include<pthread.h>


void *print(void  *x) {

    int *i = (int *)x;

    printf("x = %d\n",*i);

    return NULL;
}

int main()
{
    pthread_t pid[10];

    int x = 10;
    int i = 0;

    for(i = 0; i < 10; i++) {

        if(pthread_create(&pid[i], NULL,print,&i))
            printf("failed to create \n");
    }

    for(i = 0; i < 10; i++) 
        pthread_join(pid[i], NULL);

    return 0;
}
