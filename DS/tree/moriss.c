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

void pre(struct TNode *root)
{
    if(!root)
	return;
    printf("%d ",root->data);
    pre(root->left);
    pre(root->right);
}

void post(struct TNode *root)
{
    if(!root)
	return;
    post(root->left);
    post(root->right);
    printf("%d ",root->data);
}


void reversin(struct TNode *root)
{
    if(!root)
	return;
    reversin(root->right);
    printf("%d ",root->data);
    reversin(root->left);
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

void pre_moriss(struct TNode *root)
{
    struct TNode *cur = root;
    struct TNode *temp = NULL;
	
    while(cur) {
	if(cur->left) {
	    for(temp = cur->left; (temp->right != NULL) && (temp->right != cur) ; temp = temp->right);
	    if(temp->right == NULL) {
	        printf("%d ", cur->data);
		temp->right = cur;
	        cur = cur->left;
	    } else {
           	temp->right = NULL;  
	        cur = cur->right;
            }
      	} else {
	    printf("%d ", cur->data);
	    cur = cur->right;
	}
    }
}

void in_moriss(struct TNode *root)
{
    struct TNode *cur = root;
    struct TNode *temp = NULL;
	
    while(cur) {
	if(cur->left) {
	    for(temp = cur->left; (temp->right != NULL) && (temp->right != cur) ; temp = temp->right);
	    if(temp->right == NULL) {
		temp->right = cur;
	        cur = cur->left;
	    } else {
	        printf("%d ", cur->data);
           	temp->right = NULL;  
	        cur = cur->right;
            }
      	} else {
	    printf("%d ", cur->data);
	    cur = cur->right;
	}
    }
}

void post_moriss(struct TNode *root)
{
    struct TNode *cur = root;
    struct TNode *temp = NULL;
	
    while(cur) {
	if(cur->left) {
	    for(temp = cur->left; (temp->right != NULL) && (temp->right != cur) ; temp = temp->right);
	    if(temp->right == NULL) {
		temp->right = cur;
	        cur = cur->left;
	    } else {
           	temp->right = NULL;  
	        cur = cur->right;
            }
      	} else {
	    printf("%d ", cur->data);
	    cur = cur->right;
	}
    }
}

int main(){
    struct TNode *root = NULL;

    root = getnode(1);
    root->left = getnode(2);
    root->right = getnode(3);
    root->left->left = getnode(4);
    root->left->right = getnode(5);
    root->right->left = getnode(6);
    root->right->right = getnode(7);
    post(root);
    printf("\n");
    post_moriss(root);
    return 0;
}
