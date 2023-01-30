#include<stdio.h>

int main()
{
	char buffer[20];
	char *str = "satya";

	snprintf(buffer, 16, "this is %s", str);

	printf("%s \n", buffer);
	return 0;
}
