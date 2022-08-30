#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

void* malloc(size_t sz)
{
	void *(*libc_malloc)(size_t) = dlsym(RTLD_NEXT, "malloc");
	fprintf(stdout, "malloc\n");
	return libc_malloc(sz);
}

void free(void *p)
{
	void (*libc_free)(void*) = dlsym(RTLD_NEXT, "free");
	fprintf(stdout, "free\n");
	libc_free(p);
}
#if 0
int main()
{
	free(malloc(10));
	return 0;
}
#endif
