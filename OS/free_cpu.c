#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<assert.h>
#include<fcntl.h>
#include<errno.h>
#include<limits.h>

struct cpuinfo {
    int cpu;
    long double idletime;
    long double totaltime;
};

#define MAX_CPU 256
#define MAX_NODES 8

float cpuutil[MAX_CPU];
int numa_cpu[MAX_NODES][MAX_CPU];

void compute(struct cpuinfo *cpuutil)
{
    char str[100];
    const char d[2] = " ";
    char* token;
    int idx = 0, i = 0;
    long double sum = 0, idle;

    FILE* fp = fopen("/proc/stat","r");
    fgets(str, 100, fp);
    while (idx != MAX_CPU && fgets(str, 100, fp) != NULL) {
        token = strtok(str,d);
        sum = 0;
        idle = 0;
        while(token != NULL) {
            token = strtok(NULL,d);
            if(token != NULL){
                sum += atoi(token);
                if(i == 3)
                    idle = atoi(token);
                i++;
            }
        }
        i = 0;
        cpuutil[idx].idletime = idle;
        cpuutil[idx].totaltime = sum;
        idx++;
    }
    fclose(fp);
}

int compute_cpuutil(int targetnode)
{
    struct cpuinfo snap1[MAX_CPU];
    struct cpuinfo snap2[MAX_CPU];
    int idx = -1;
    int cpu = 0;
    compute(snap1);
    sleep(1);
    compute(snap2);

    memset(cpuutil, 0, sizeof(cpuutil));
    while ((idx = numa_cpu[targetnode][cpu]) != -1) {
            double total_delta = snap2[idx].totaltime- snap1[idx].totaltime;
            double idle_delta = snap2[idx].idletime - snap1[idx].idletime;
            cpuutil[idx]  = 100.0 * (1.0 - idle_delta / total_delta);
            if (cpuutil[idx] == 0.0) { printf("Node %d free cpu %d \n", targetnode, idx); return idx;}
            cpu++;
    }
    return -1;
}

static int read_cpu_node(int cpu, char *buffer, int buffer_size)
{
        char filename[PATH_MAX];
        int fd, bytes;

        snprintf(filename, sizeof(filename),
                 "/sys/devices/system/node/node%d/cpumap", cpu);
        fd = open(filename, O_RDONLY);
        if (fd < 0)
                return -EINVAL;

        bytes = read(fd, buffer, buffer_size);
        close(fd);

        return bytes;
}

static int fill_cpu_nodes()
{
        char cpu_map[1024];
        int node, fd, bytes;

        memset(numa_cpu, -1, sizeof(numa_cpu));

        for (node = 0; node < MAX_NODES ; node++) {
                bytes = read_cpu_node(node, cpu_map, sizeof(cpu_map));
                if (bytes <= 1)
                        break;
                populate_cpu_map(fd, node, cpu_map, bytes - 1);
        }

        return node;
}

int main()
{
    fill_cpu_nodes();
    compute_cpuutil(1);

    return 0;
}
   
