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

void succpred(struct Node *root, int key, int *suc, int *pred)
{
  struct Node *temp = NULL;

  if(root == NULL) return;

  if(root->data == key) {
     temp = root->left;
     if(temp) {
        while(temp->right) {
	      temp = temp->right;
        }
        *pred = temp->data;
     }

     temp = root->right;
     if(temp) {
        while(temp->left) {
	     temp = temp->left;
        }
        *suc= temp->data;
     }
     return;
  } else if (key < root->data) {
     *suc = root->data;
     succpred(root->left, key, suc, pred);
  } else {
     *pred = root->data;
     succpred(root->right, key, suc, pred);
  }    
}

void keys_in_rang(struct Node *root, int key1, int key2)
{
   if(root == NULL) return;
   
   if( key1 < root->data)
      keys_in_rang(root->left, key1, key2);
 
   if(root->data > key1 && root->data < key2) 
       printf("%d->",root->data);
  
   if(key2 > root->data)
      keys_in_rang(root->right, key1, key2);

}
int main(int argc , char **argv)
{
    int suc, prec;
    struct Node *root = get_node(60);
    root->left        = get_node(40);
    root->right       = get_node(80);
    root->left->left  = get_node(30);
    root->left->right = get_node(50);
    root->right->left  = get_node(70);
    root->right->right = get_node(90);
   // inorder(root);
   // printf("dat %d \n",2 * atoi(argv[1]));
   // succpred(root, atoi(argv[1]), &suc, &prec);

   //  printf("suc = %d pred = %d\n",suc, prec);
    keys_in_rang(root,25,81);
    return 0;
}
