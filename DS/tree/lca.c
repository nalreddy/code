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

struct Node * lca(struct Node *root, struct Node *n1, struct Node *n2)
{
   struct Node *left_lca = NULL,*right_lca = NULL;

   if(root == NULL) return NULL;

   if(root == n1) {
     return root;
   }
   if(root == n2) {
     return root;
   }

   left_lca = lca(root->left, n1, n2);
   right_lca = lca(root->right, n1, n2);
  
   if(left_lca && right_lca) {
        printf("lca at %p\n",root);
       return root;
    }
   return left_lca ? left_lca : right_lca; 
}

void delete_tree(struct Node *root)
{
   if(root == NULL) return;

   delete_tree(root->left);
   delete_tree(root->right);

   free(root);
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
    printf("left %p right = %p\n",root->left->left, root->left->right);
    temp = lca(root, root->left->left, root->left->right);
    printf("temp = %p\n", temp);
    if(temp)
       printf("lca of %d root->left = %p data =%d \n", temp->data, root->left, root->left->data); 
    return 0;
}
