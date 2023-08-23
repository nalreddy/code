#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int dst_node;

double get_bandwidth()
{
	FILE *fp;
	char buffer[1024];
	char *token;
	double bandwidth;
	int i = 1;

	fp = popen("/usr/bin/numastat -m  |/usr/bin/grep -i used", "r");
	if (!fp)
		return -errno;

	if (!fgets(buffer, sizeof(buffer) - 1, fp))
		return -EINVAL;

	token = strtok(buffer, " ");
	while(token)
	{
		if (i == (dst_node + 2)) {
			bandwidth = atof(token);
			break;
		}
		i++;
		token = strtok(NULL, " "); 
	}
	pclose(fp);
	return bandwidth;	
}

int main(int argc, char **argv)
{
	double past = 0, cur = 0, seed = 0;
	double max = 0;
	double band = 0;
	int fd;
	char str[32];
	int i = 0;
	char *test_name;
	char *prefix = "/home/satyan/tools/memory_bandwidth_";
	char file_path[256];

	if (argc < 3) {
		printf("Invalid arguments \n");
		return -1;
	}

	dst_node = atoi(argv[1]);
	test_name  = argv[2];

	snprintf(file_path, sizeof(file_path), "%s%s%s", prefix, test_name, ".txt");
	printf("file %s destination node %d \n", file_path, dst_node);

	fd = open(file_path, O_CREAT | O_RDWR | O_TRUNC,  S_IRWXU | S_IRWXO | S_IRWXG);
	if (fd < 0) {
		printf("Failed to open file %d\n", errno);
		return -1;
	}

	seed = get_bandwidth();	
	if (seed < 0) {
		printf("Invalid seed value \n");
		return -1;
	}

	printf("Seed %0.2f \n", seed );

	while(1)
	{
		past = get_bandwidth();
		sleep(1);
		cur = get_bandwidth();

		if ((past || cur ) < 0) {
			printf("Error past %d cur %d \n", past, cur);
			return -1;
		}
		if (cur >= past) {
			band = cur - past;
			if (cur > max)
				max  = cur; 

			snprintf(str, 32, "%.2f\n", band);
			write(fd, &str, strlen(str));
		}
		if (i == 2) {
			printf("moved memory %0.2f \n", (max - seed));
			i = 0;
		}
		i++;
	}
	return 0;
}
