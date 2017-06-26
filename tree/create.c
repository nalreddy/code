#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *left,*right;
};

struct node * get_node(int data)
{
 struct node *temp = (struct node *) malloc(sizeof(struct node));

 if(!temp)
    return NULL;
 temp->data = data;
 temp->left = NULL;
 temp->right = NULL;

 return NULL;
}

int main()
{

return 0;
}

