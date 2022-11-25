#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<ctype.h>

int main() {
	char *str ="10-0,200,300";
	char *end = NULL;

	if (str == NULL || *str == '\0' || !isdigit(*str)) {
		printf("error \n");
		return -EINVAL;
	}

	 unsigned int result = (unsigned int) strtoul(str, &end, 10);
	 if (errno) {
		 printf("error \n");
		 return -1;
	 }
	 printf("number %ld \n", result); 
	str = strchr(str, ',');
	printf(" str %s \n",str);
	str++;
	printf(" str %s \n",str);
	return 0;
}
