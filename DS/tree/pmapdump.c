#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#define __USE_GNU
#include <search.h>

typedef unsigned int __u32, u32;
typedef unsigned long __u64, u64;

struct bst_node {
    unsigned long basepage;
	int refcount;
};

struct bst_node_dummy {
    unsigned long basepage;
};


static void usage(const char *cmd)
{
	printf("Usag : %s <pid>\n", cmd);
}


static struct bst_node * alloc_node()
{
	return malloc(sizeof(struct bst_node));
}
static int bst_cmp(const void *firstp, const void *secondp)
{
    struct bst_node *first  = (struct bst_node *)firstp;
    struct bst_node *second = (struct bst_node *)secondp;

    if (first->basepage < second->basepage)
        return -1;

    if (first->basepage > second->basepage)
        return 1;

    return 0;
}

static void init_node(struct bst_node *node, unsigned long baseaddr)
{
    node->basepage = baseaddr;
	node->refcount = baseaddr*2;
}

static void update_node(struct bst_node *node, unsigned long baseaddr)
{
    node->basepage = baseaddr;
	node->refcount = baseaddr*3;
}

static int add_to_bst(struct bst_node **root, unsigned vaddr)
{
    struct bst_node *node, *new_node, **nodepp;
    struct bst_node_dummy dummy;

    if (*root) {
        nodepp = tfind(&dummy, (void **)root, bst_cmp);
            if (nodepp) {
            node = *nodepp;
            update_node(node, vaddr);
            return 0;
        }
    }

    new_node = alloc_node();
    if (!new_node)
        return -ENOMEM;

    init_node(new_node, vaddr);
    nodepp = tsearch(new_node, (void **)root, bst_cmp);
    if (nodepp) {
        node = *nodepp;
        assert(*nodepp == new_node);
    }

    return 0;
}

int main(int argc, char *argv[])
{
	struct bst_node *root = NULL;
	struct bst_node *node;
	struct bst_node **nodepp;

	for (unsigned long i = 0; i < 20; i++)
	{
		add_to_bst(&root, i);
	}

	for (unsigned long i = 0; i < 20; i++)
	{
		struct bst_node_dummy dummy;

		dummy.basepage = i;

		if (root) {
			nodepp = tfind(&dummy, &root, bst_cmp);
			if (nodepp) {
				node = *nodepp;
				assert(node->basepage == i);
				printf(" node %d ref %d \n", node->basepage, node->refcount);
			}
		}

	}
	return 0;
}
