#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define false 0
#define bool int
static bool is_cpu_online(int cpu)
{
        int fd, ret;
        char online;
        char dev[1024];

        snprintf(dev, sizeof(dev),
                "/sys/devices/system/cpu/cpu%d/online", cpu);
        fd = open(dev, O_RDONLY);
        if (fd < 0)
                return false;

        online = 0;
        ret = read(fd, &online, sizeof(online));
        close(fd);

        if (ret < 0)
                return false;

        return online;
}


int main() {
	int i = 0;
	int nr_cpus = sysconf(_SC_NPROCESSORS_ONLN);
	
	for ( ; i < nr_cpus; i++) {
		if (!is_cpu_online(i)) {
			printf("nope %d \n", i);
		} else {
			printf(" yes online %d\n",i);
		}
	}
}
