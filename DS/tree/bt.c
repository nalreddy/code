#include<stdio.h>
#include<stdlib.h>

struct TNode
{
   struct TNode *left;
   struct TNode *right;
   int data;
};

struct TNode * getnode(int x){
 struct TNode *temp = (struct TNode *) malloc(sizeof(struct TNode));
 temp->left = NULL;
 temp->right = NULL; 
 temp->data = x;
 return temp;
}

void in(struct TNode *root)
{
    if(!root)
	return;
    in(root->left);
    printf("%d ",root->data);
    in(root->right);
}

void delebt(struct TNode **root)
{
    if(!*root)
	return;
    delebt(&((*root)->left));
    delebt(&((*root)->right));
    free(*root);
    *root = NULL;
}

int search(struct TNode *root, int x)
{
    if(!root)
       return 0;
    if(root->data == x)
      return 1;
   
    return (search(root->left, x) || search(root->right, x));
}

int size(struct TNode *root){

    if(!root)
	return 0;
    return 1 + size(root->left) + size(root->right);

}

int height(struct TNode *root){
    int rh = 0,lh = 0;
    if(!root)
	return 0;

    lh = height(root->left);
    rh = height(root->right);
    if(lh > rh)
	return lh + 1;
    else
	return rh + 1;
}

int diameter(struct TNode *root, int *h)
{
  int lh = 0,rh = 0,ld = 0, rd = 0;     
  int temp = 0;

  if(!root) {
      *h = 0;
      return 0;
   }    

   ld = diameter(root->left, &lh);
   rd = diameter(root->right, &rh);
   
   *h = lh > rh ? lh + 1 : rh + 1;
  
   temp = ld > rd ? ld : rd;

   
   return temp > (lh + rh ) ? temp : (lh + rh);
}

int main(){
    struct TNode *root = NULL;
    int h = 0;
    root = getnode(10);
    root->left = getnode(5);
    root->left->left = getnode(8);
    root->right = getnode(3);
    root->right->right = getnode(2);
    root->right->right->right = getnode(6);
    in(root);
    if(search(root,2))
	    printf("\nfound\n");
    else
	    printf("not found\n");
    printf("size = %d\n",size(root));
    printf("height = %d\n",height(root));
    printf("diameter = %d\n", diameter(root, &h));

    delebt(&root);
    if(!root)
	printf("freed\n");
    return 0;
}
