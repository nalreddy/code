#include<stdio.h>
#include<string.h>

int main()
{
	int a[10][10];

	memset(a, -1, sizeof(a));

	printf("size of %d \n", sizeof(a));

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("val %d\n", a[i][j]);
		}
	}
	return 0;
}
