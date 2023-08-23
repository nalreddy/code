#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/vmalloc.h>
#include <linux/fs.h>
#include <linux/blkdev.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/blk-mq.h>
#include <linux/hrtimer.h>
#include <linux/delay.h>
#include <linux/cpumask.h>
#include <linux/smp.h>
#include <linux/wait.h>
#include <linux/cpumask.h>
#include <linux/module.h>
/*
eg. sudo insmod ./node.ko  numa_node3=128

This will steal 128GB memory from node3 until the module is unloaded.

*/
/*
	allocate memory using mallock locked memory
	getchar() wait untill kill 
	in user space mlock
*/
static struct page **my_pages;
static unsigned long my_pages_cnt;
static int numa_node0;
static int numa_node1;
static int numa_node2;
static int numa_node3;
static int numa_node4;
static int numa_node5;
static int numa_node6;
static int numa_node7;
module_param(numa_node0, int, 0);
module_param(numa_node1, int, 0);
module_param(numa_node2, int, 0);
module_param(numa_node3, int, 0);
module_param(numa_node4, int, 0);
module_param(numa_node5, int, 0);
module_param(numa_node6, int, 0);
module_param(numa_node7, int, 0);
MODULE_PARM_DESC(numa_node0, "size in gigabytes to allocate from node 0");
MODULE_PARM_DESC(numa_node1, "size in gigabytes to allocate from node 1");
MODULE_PARM_DESC(numa_node2, "size in gigabytes to allocate from node 2");
MODULE_PARM_DESC(numa_node3, "size in gigabytes to allocate from node 3");
MODULE_PARM_DESC(numa_node4, "size in gigabytes to allocate from node 4");
MODULE_PARM_DESC(numa_node5, "size in gigabytes to allocate from node 5");
MODULE_PARM_DESC(numa_node6, "size in gigabytes to allocate from node 6");
MODULE_PARM_DESC(numa_node7, "size in gigabytes to allocate from node 7");

#define DEFAULT_SIZE 8
#define MAX_NUMA 4

static int __init node_init(void)
{
	unsigned long i, j, max_pages;
	struct page *page;
	unsigned long pages_per_numa[MAX_NUMA];
	int numa;


	if (!numa_node0 && !numa_node1 && !numa_node2 && !numa_node3 &&
	    !numa_node4 && !numa_node5 && !numa_node6 && numa_node7) {
		numa_node0 = DEFAULT_SIZE;
	}

	max_pages  = numa_node0 + numa_node1 + numa_node2;
	max_pages += numa_node3 + numa_node4 + numa_node5;
	max_pages += numa_node6 + numa_node7;
	max_pages *= (1024 * 1024 * 1024) / PAGE_SIZE;
	
	pages_per_numa[0] = numa_node0 * (1024UL * 1024 * 1024) / PAGE_SIZE;
	pages_per_numa[1] = numa_node1 * (1024UL * 1024 * 1024) / PAGE_SIZE;
	pages_per_numa[2] = numa_node2 * (1024UL * 1024 * 1024) / PAGE_SIZE;
	pages_per_numa[3] = numa_node3 * (1024UL * 1024 * 1024) / PAGE_SIZE;
	pages_per_numa[4] = numa_node4 * (1024UL * 1024 * 1024) / PAGE_SIZE;
	pages_per_numa[5] = numa_node5 * (1024UL * 1024 * 1024) / PAGE_SIZE;
	pages_per_numa[6] = numa_node6 * (1024UL * 1024 * 1024) / PAGE_SIZE;
	pages_per_numa[7] = numa_node7 * (1024UL * 1024 * 1024) / PAGE_SIZE;

	for (i = 0; i < MAX_NUMA; i++)
		printk("numa_node%ld pages %ld size %ld gb\n",
			i,
			pages_per_numa[i],
			pages_per_numa[i] * 4096 / (1024 * 1024 * 1024));

	my_pages = vmalloc(sizeof(*my_pages) * max_pages);
	if (!my_pages)
		return -ENOMEM;

	memset(my_pages, 0, sizeof(*my_pages) * max_pages);

	numa = 0;
	i    = 0;

	while (numa < MAX_NUMA && i < max_pages) {
		for (j = 0; j < pages_per_numa[numa]; j++) {
			page = alloc_pages_node(numa,
						GFP_KERNEL|__GFP_THISNODE,
						0);
			if (!page)
				break;
			my_pages[i++] = page;
		}

		numa++;
	}

	my_pages_cnt = i;

	printk("pages allocated %ld gigabytes %ld\n",
		my_pages_cnt, my_pages_cnt * PAGE_SIZE / (1024UL * 1024 * 1024));

	
	return 0;
}

static void __exit node_exit(void)
{
	unsigned long i;

	printk("pages freed %ld\n", my_pages_cnt);

	if (!my_pages)
		return;

	for (i = 0; i < my_pages_cnt; i++)
		put_page(my_pages[i]);

	vfree(my_pages);
}

module_init(node_init);
module_exit(node_exit);
MODULE_AUTHOR("GOD");
MODULE_LICENSE("GPL");
