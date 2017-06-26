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
 
int findMaxPathsum(struct Node*root, int *sum)
{
    int lsum = 0;
    int rsum = 0;
    int max_single_path = 0;
    int max_top_sum = 0;

    if (root == NULL)
        return 0;
     //@root left sum
     // right sum 
    lsum = findMaxPathsum(root->left, sum);
    rsum = findMaxPathsum(root->right, sum);
 
    max_single_path = max(max(lsum, rsum) + root->data, root->data);

    max_top_sum = max(max_single_path, lsum + rsum + root->data);
 
    *sum = max(*sum, max_top_sum); //Maximum Result.
 
    return max_single_path;
}
 
int findMaxSum(struct Node *root)
{
  int result = INT_MIN;
 
  findMaxPathsum(root, &result);
  return result;
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
    struct Node *root = get_node(100);
    root->left        = get_node(15);
    root->right       = get_node(20);
    root->left->left  = get_node(5);
    root->left->right = get_node(10);
    root->right->left  = get_node(-30);
    root->right->right = get_node(-40);
    printf("Max path sum is %d",findMaxSum(root));
    delete_tree(root);
    return 0;
}
