#include <stdio.h>
#include <stdlib.h>

#define page_size 4096
#define KB 1024ull
#define MB (1024ull * KB)
#define GB (1024ull * MB)
#define TB (1024ull * GB)

unsigned long long get_capacity(int bandwidth_config, int bandwidth)
{
    static int config = 0;
    unsigned long long capacity = 0;

    switch (bandwidth_config) {
    case 'K':
        capacity = bandwidth * KB;
        break;
    case 'M':
        capacity = bandwidth * MB;
        break;
    case 'G':
        capacity = bandwidth * GB;
        break;
    case 'T':
        capacity = bandwidth * TB;
        break;
    }
    config++;
    if (config > 1)
        return 0;
    return (capacity / page_size);
}

int main(int argc, char **argv)
{
	unsigned long long cap;
	int config = (char ) (*argv[1]); 
	int bandwidth = atoi(argv[2]);

	printf("config %d and band %d \n", config, bandwidth); 
	cap = get_capacity(config, bandwidth);
	if (cap < 0)
	{
		printf("invalid value %lu\n", cap );
	} else  {
		printf("cap value %lu\n", cap );
	}
	
	cap = get_capacity(config, bandwidth);
	if (cap < 0)
	{
			printf("invalid value %lu\n", cap );
	} else  {
			printf("cap value %lu\n", cap );
	}

	return 0;
}
