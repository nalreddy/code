#include <time.h>
#include<unistd.h>
#include <stdio.h>

int main()
{
	unsigned int time_spent;
    clock_t tic = clock();

	sleep(10);
    clock_t toc = clock();

	time_spent = ((double)(toc - tic) / CLOCKS_PER_SEC) * 1000;
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    printf("Elapsed: %u millisecond\n", time_spent);

	double test = 0.0;
	unsigned int try = 1;

	if (test && try)
	{
		printf("saved \n");
	} else {
		printf("truncated \n");
	}
    return 0;
}
