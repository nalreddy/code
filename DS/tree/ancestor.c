#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define true 1
#define false 0

struct Node
{
    int data;
    struct Node* left, *right;
};

int max(int a, int b) {
  
  return a >= b ? a: b;
}

struct Node* get_node(int data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int ancestor(struct Node *root, struct Node *n) 
{
    if(root == NULL) return false;

    if(root == n)
	return true;
    if(ancestor(root->left, n) || ancestor(root->right, n)) {
       printf("%d\n", root->data);
       return true;
    }
    return false;
}
int main(void)
{
    struct Node *temp = NULL;
    struct Node *root = get_node(60);
    root->left        = get_node(40);
    root->right       = get_node(80);
    root->left->left  = get_node(30);
    root->left->right = get_node(50);
    root->right->left  = get_node(70);
    root->right->right = get_node(90);
    ancestor(root, root->left->left);
    return 0;
}
