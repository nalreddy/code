#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<string.h>

using namespace std;

int main()
{
    int fd = ::open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        cout << " Failed to open file test " << endl;
        //exit;
    }

    char* chunk = reinterpret_cast<char*>(mmap(NULL, 1024, PROT_READ, MAP_FILE | MAP_SHARED, fd, 0));
    char* addr = chunk;

    char str[64];
    memcpy(str, addr, 10);
    cout << str<< endl;

    munmap(addr, 1024);

    return 0;
}
