#include<stdio.h>


int main()
{
	for(int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 5)
			{
				printf("breaking \n");
				break;
			}
		}
		printf("i =  %d \n", i);
	}
}

