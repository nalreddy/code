#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct intervel 
{
    int low, high;
};

struct Node
{
    struct intervel i; 
    struct Node* left, *right;
};

int max(int a, int b) {
  
  return a >= b ? a: b;
}

struct Node* get_node(struct intervel i)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->i.low = i.low;
    newNode->i.high = i.high;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct Node *root)
{
  if(root == NULL) return;
  inorder(root->left);
  printf("interval low %d high %d\n",root->i.low, root->i.high);
  inorder(root->right);
}

int is_conflict(struct intervel i1, struct intervel i2)
{
    if ((i1.low < i2.high) && ( i2.low < i1.high)) 
        return 1;
    else 
        return 0;
}

struct Node *insert(struct Node *root, struct intervel i) 
{

    if (root == NULL) {
        printf("making node\n");
        return get_node(i);
    }

    if(is_conflict(root->i,i)) {
        printf("conflicting\n");
        printf("interval low %d high %d i.low %d i.high %d\n",root->i.low, root->i.high, i.low, i.high);
        return NULL;
    }

    if (i.high < root->i.low)
        root->left = insert(root->left,i);
    else
        root->right = insert(root->right,i);

    return root;
}

int main(int argc , char **argv)
{
    struct intervel it[] = {{2,3},{4,7},{5,8},{9, 11}};
    int i = 0;


    struct Node *root = NULL;
    
    
    root = insert(root, it[0]);

    insert(root, it[1]);
    insert(root, it[2]);
    inorder(root);
   return 0;
}
