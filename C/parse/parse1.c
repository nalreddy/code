#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>

static const char *nexttoken(const char *q,  int sep)
{
        if (q)
                q = strchr(q, sep);
        if (q)
                q++;
	return q;   
}

static int nextnumber(const char *str, char **end, unsigned int *result)
{
        errno = 0;
        if (str == NULL || *str == '\0' || !isdigit(*str))
                return -EINVAL;
        *result = (unsigned int) strtoul(str, end, 10);
        if (errno)
                return -errno;
        if (str == *end)
                return -EINVAL;
        return 0;
}

int cpulist_parse(const char *str)
{
        const char *p, *q;
        char *end = NULL;

        q = str;

        while (p = q, q = nexttoken(q, ','), p) {
                unsigned int a; /* beginning of range */
                unsigned int b; /* end of range */
                unsigned int s; /* stride */
                const char *c1, *c2;

                if (nextnumber(p, &end, &a) != 0)
                        return 1;
		printf("number result %d p %s q %s end %s", a, p ,q, end);
                b = a;
                s = 1;
                p = end;

                c1 = nexttoken(p, '-');
                c2 = nexttoken(p, ',');

		printf(" c1 %s c2 %s\n", c1,c2);
                if (c1 != NULL) {// && (c2 == NULL || c1 < c2) ) {
                        if (nextnumber(c1, &end, &b) != 0)
                                return 1;
#if 0
                        c1 = end && *end ? nexttoken(end, ':') : NULL;

		      printf(" 2 c1 %s , c2 %s \n", c1, c2);
                        if (c1 != NULL && (c2 == NULL || c1 < c2)) {
                                if (nextnumber(c1, &end, &s) != 0)
                                        return 1;
                                if (s == 0)
                                        return 1;
                        }
#endif
                }

                if (!(a <= b))
                        return 1;
                while (a <= b) {
			printf("number a %d\n",a);
                        a += s;
                }
        }

        if (end && *end)
                return 1;
        return 0;
}

int main() {

//	char *str = "0,1,2,6-10,11,12";
	char *str = "0,1,2,6-10";
	cpulist_parse(str);
	return 0;
}
