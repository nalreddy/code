#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void inorder(struct Node *root)
{
  if(root == NULL) return;
  inorder(root->left);
  printf("%d->",root->data);
  inorder(root->right);
}

void largest(struct Node *root, int k, int *c)
{
   if(root == NULL || *c > k) {
       return;
    }
   largest(root->right, k, c);

   *c = *c + 1;
   if(*c == k) {
      printf("%d \n", root->data);
      return;
    }
   largest(root->left, k, c);
}

int main(int argc , char **argv)
{
    int c = 0;
    struct Node *root = get_node(60);
    root->left        = get_node(40);
    root->right       = get_node(80);
    root->left->left  = get_node(30);
    root->left->right = get_node(50);
    root->right->left  = get_node(70);
    root->right->right = get_node(90);
 
    largest(root, atoi(argv[1]) , &c);
    return 0;
}
