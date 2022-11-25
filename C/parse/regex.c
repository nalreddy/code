#define _GNU_SOURCE
#include <sched.h>

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

int cpulist_parse(const char *str, cpu_set_t *cpusetp, size_t size)
{
	const char *p, *q;
	char *end = NULL;
	int a; /* beginning of range */
	int b; /* end of range */
	int s; /* stride */
	const char *c1,*c2;

        q = str;
	p = q;


	while(p) {
		q = nexttoken(q,',');

		printf("end %s \n", end);
		if (nextnumber(p, &end, &a) != 0)
			return 1;
		b = a;
		s = 1;
		p = end;

                c1 = nexttoken(p, '-');
                c2 = nexttoken(p, ',');

	//	printf(" c1 %s , c2 %s \n", c1, c2);
                if (c1 != NULL && ( c2 == NULL || c1 < c2)) {
	//		printf(" level 2c1 %s , c2 %s \n", c1, c2);
                        if (nextnumber(c1, &end, &b) != 0)
				return 1;
		}
                if (!(a <= b))
                        return 1;
                while (a <= b) {
			printf("number a %d stride %ld \n",a, s);
			CPU_SET_S(a, size, cpusetp);
                        a += s;
                }
		p = q;
		printf("p = %s \n", p);
	}
//	printf("str %s \n",str);

#if 0
        while (p = q, q = nexttoken(q, ','), p) {
                unsigned int a; /* beginning of range */
                unsigned int b; /* end of range */
                unsigned int s; /* stride */
                const char *c1,*c2;

                if (nextnumber(p, &end, &a) != 0)
                        return 1;
		printf("number result %d p %s q %s end %s", a, p ,q, end);
                b = a;
                s = 1;
                p = end;

                c1 = nexttoken(p, '-');
                c2 = nexttoken(p, ',');

		printf(" c1 %s , c2 %s \n", c1, c2);
                if (c1 != NULL && (c2 == NULL || c1 < c2)) {
                        if (nextnumber(c1, &end, &b) != 0)
                                return 1;

#if 0
                        c1 = end && *end ? nexttoken(end, ':') : NULL;
		      printf(" 2 c1 %s , c2 %s \n", c1, c2);
                        if (c1 != NULL && (c2 == NULL || c1 < c2)) {
                                if (nextnumber(c1, &end, &s) != 0)
                                        return 1;
				printf("stride %ld \n", s);
                                if (s == 0)
                                        return 1;
                        }
#endif
                }

                if (!(a <= b))
                        return 1;
                while (a <= b) {
			printf("number a %d stride %ld \n",a, s);
                        a += s;
                }
        }
#endif
        return 0;
}

int main() {

//	char *str = "1,2,3,1-5,7-15";
	//char *str = "0,1,2,3";
	char *str = "0,1,2,6-12";
	//char *str = "4-10,15,16,17";
//	char *str = "0,1,2,10-15,20-30,5,6,7";
//	cpu_set_t *cpusetp;
	size_t size;
	int num_cpus = 256;
	cpu_set_t *cpusetp;
	int cpu;

	cpusetp = CPU_ALLOC(num_cpus);
	if (cpusetp == NULL) {
		perror("CPU_ALLOC");
		exit(EXIT_FAILURE);
	}
	size = CPU_ALLOC_SIZE(num_cpus);
	CPU_ZERO_S(size, cpusetp);

	cpulist_parse(str, cpusetp, size);

	for (cpu = 0; cpu < num_cpus; cpu += 1) {
		if (CPU_ISSET(cpu, cpusetp)) {
			printf("cpu set %d\n",cpu);
		} else {
			//		 printf("cpu not set %d\n",cpu);
		}
	}

	return 0;
}
