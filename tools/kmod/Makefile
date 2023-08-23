TARGET = node
KVERSION = $(shell uname -r)
obj-m += ${TARGET}.o
KERN := /home/skurichi/fedora
${TARGET}-objs := node_src.o
all:
	#make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
	make -C ${KERN} M=$(PWD) modules
 
clean:
	make -C ${KERN} M=$(PWD) clean
