#include<stdio.h>

int main()
{
	int x = 6;

	for (int i = 0; i < sizeof(int) * 8; i++)
	{
		if (x & (1 << i))
		{
			printf("set at %d \n",i);
		}
	}



}
