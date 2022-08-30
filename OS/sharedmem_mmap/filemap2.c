#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	if(argc < 2){
		printf("File path not mentioned\n");
		exit(0);
	}

	const char *filepath = argv[1];
	int fd = open(filepath, O_RDWR);
	if(fd < 0){
		printf("\n\"%s \" could not open\n",
				filepath);
		exit(1);
	}

	write(fd, "satya", 6);

	struct stat statbuf;
	int err = fstat(fd, &statbuf);
	if(err < 0){
		printf("\n\"%s \" could not open\n",
				filepath);
		exit(2);
	}

	char *ptr = mmap(NULL,statbuf.st_size,
			PROT_READ,MAP_PRIVATE,
			fd,0);
	if(ptr == MAP_FAILED){
		printf("Mapping Failed\n");
		close(fd);
		return 1;
}
	close(fd);

	ssize_t n = write(1,ptr,statbuf.st_size);
	if(n != statbuf.st_size){
		printf("Write failed");
	}



	err = munmap(ptr, statbuf.st_size);

	if(err != 0){
		printf("UnMapping Failed\n");
		return 1;
	}
	return 0;
}
