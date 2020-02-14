#include<stdio.h>
#include<stdlib.h>

#define SIZE 1
#define NUMELEM 5


int main(void)
{
    FILE* fd = NULL;

    fd = fopen("test.txt","rw+");

    if(NULL == fd)
    {
        printf("\n fopen() Error!!!\n");
        return 1;
    }


#if 0
    if(0 != fseek(fd,11,SEEK_CUR))
    {
        printf("\n fseek() failed\n");
        return 1;
    }

    printf("\n fseek() successful\n");
#endif
 //   fwrite(buff,SIZE,strlen(buff),fd);
   


    fclose(fd);


    return 0;
}
