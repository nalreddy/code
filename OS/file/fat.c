#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
    FILE* fw = NULL;
    FILE* fr = NULL;
    char *buff = (void *) malloc(1024);
    char *clean = (void *) malloc(4096);
    memset(clean, 0, 4096); 

    fr = fopen(argv[1],"r");
    fw = fopen(argv[2],"rw+");

    fread(buff,1 , 1024,fr);
    fwrite(clean,1,4096,fw);
    fseek(fw, 1024,SEEK_SET);
    fwrite(buff,1,1024,fw);
#if 0 
    fwrite(clean,1,4096,fw);
    fseek(fw, 4096,SEEK_SET);
    fwrite(clean,1,4096,fw);
    fseek(fw, 5120,SEEK_SET);
    fwrite(buff,1,1024,fw);
#endif
    fclose(fw);
    fclose(fr);
    free(buff);
    free(clean);
    return 0;
}
