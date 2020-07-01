#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include<unistd.h>

using namespace std; 

int main() 
{ 
    // ftok to generate unique key 
    key_t key = ftok("shmfile",65); 

    // shmget returns an identifier in shmid 
    int shmid = shmget(key,10000,0666|IPC_CREAT |SHM_HUGETLB); 

    // shmat to attach to shared memory 
    char *str = (char*) shmat(shmid,(void*)0,0); 

    std::cout<<"Write Data : "; 
    std::cin >> str;
//    gets(str); 

    printf("Data written in memory: %s\n",str); 

    sleep(1000);
    //detach from shared memory 
    shmdt(str); 

    return 0; 
} 

