
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <pthread.h>

int main()
{
    pthread_mutexattr_t attributes;

    pthread_mutexattr_init(&attributes;);
    pthread_mutexattr_setpshared(&attributes;, PTHREAD_PROCESS_SHARED);

    int handle = shm_open("/shm", O_CREAT | O_RDWR, 0777);
    ftruncate(handle, 2048*sizeof(int));
    char *memory = (char *)mmap(0, 2048*sizeof(int), PROT_READ | PROT_WRITE,
            MAP_SHARED, handle, 0);

    // mutex share
    pthread_mutex_t *mutex = (pthread_mutex_t*)memory;
    pthread_mutex_init(mutex, &attributes;);

    pthread_mutexattr_destroy(&attributes;);

    // variable share
    int *count = (int*)(memory + sizeof(pthread_mutex_t));
    *count = 0;
    printf("Initial count = %d\n", *count);

    int value_returned_from_child = 0;
    pid_t pid = fork();
    if(pid == 0) {
        pthread_mutex_lock(mutex);
        (*count)++;
        printf("Child process increased the count to %d\n", *count);
        pthread_mutex_unlock(mutex);
        value_returned_from_child = 99;
    }
    else {
        int status;
        // waiting for the child process to finish
        waitpid(pid, &status;, 0);
        value_returned_from_child = WEXITSTATUS(status);
        printf("value_returned_from_child = %d\n", value_returned_from_child);
        pthread_mutex_lock(mutex);
        (*count)++;
        printf("Parent process increased the count to %d\n", *count);
        pthread_mutex_unlock(mutex);
    }

    munmap(memory, 2048*sizeof(int));
    shm_unlink("/shm");
    return value_returned_from_child;
}
