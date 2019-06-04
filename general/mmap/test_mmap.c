#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

int main(void) {
    size_t pagesize = getpagesize();
    int unmap_result;
    char *region = NULL;

    printf("System page size: %zu bytes\n", pagesize);

#if 0
    region = (char *) mmap(
            (void*) (pagesize * (1 << 20)),   // Map from the start of the 2^20th page
            pagesize,                         // for one page length
            PROT_READ|PROT_WRITE|PROT_EXEC,
            MAP_ANON|MAP_PRIVATE, -1, 0);
#endif
    region = (char *) mmap(
            0,
            pagesize,                         // for one page length
            PROT_READ|PROT_WRITE|PROT_EXEC,
            MAP_ANON|MAP_PRIVATE, -1, 0);

    if (region == MAP_FAILED) {
        perror("Could not mmap");
        return 1;
    }

    strcpy(region, "Hello, poftut.com");

    printf("Contents of region: %s\n", region);

    unmap_result = munmap(region, 1 << 10);

    // getpagesize
    return ;
}
