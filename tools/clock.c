#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
	clock_t start = clock();
	for (int i = 0; i < 5;i++)
	{
	//	sleep(1);
	}
	clock_t end = clock() - start;
	printf("time %f \n", (float)end /CLOCKS_PER_SEC);
	return 0;
}

