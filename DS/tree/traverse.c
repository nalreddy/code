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


struct stack_node
{
 struct stack_node *next;
 struct TNode *root;
};


struct stack
{
 struct stack_node *top;
};

struct stack_node * getstacknode(struct TNode *root)
{
  struct stack_node *temp = (struct stack_node *) malloc(sizeof(struct stack_node));
  temp->root = root;
  temp->next = NULL;
  return temp;
}

void push(struct stack *st, struct TNode *root) 
{
  struct stack_node *temp = getstacknode(root);
  if(st->top == NULL) {
     st->top = temp;
   } else {
     temp->next = st->top;
     st->top = temp;
   }
}
 
void pop(struct stack *st)
{
 struct stack_node *temp = NULL;

 if(st->top == NULL) {
    printf("stack empty\n");
 } else {
    temp = st->top;
    st->top = temp->next;
  //  printf("poping %d \n", temp->root->data);
    free(temp);  
 }
}

int empty(struct stack *st)
{
  return (st->top == NULL);
}


struct TNode * peek(struct stack *st)
{
 struct stack_node *cur = NULL;
 if(empty(st))
    return NULL;

  cur = st->top;
  return (cur->root);
}

void print_stack(struct stack *st)
{
  struct stack_node *cur = st->top;
  struct TNode *t_cur;

  while(cur) {
      t_cur = cur->root; 
      printf("%d ", t_cur->data);
      cur = cur->next;
  }
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

void in_stack(struct TNode *root, struct stack *st)
{
    if(!root)
       return;

    while(1) {
          if(root) {
             push(st, root);
             root = root->left;
          } else {
             if(empty(st))
                 return;
             root = peek(st);
             printf("%d ", root->data);
             root = root->right;
             pop(st);
          } 
    }
}

int main(){
    struct TNode *root = NULL;
    struct stack *st = NULL;
    st = (struct stack *) malloc(sizeof(struct stack ));
    st->top = NULL;

    root = getnode(1);
    root->left = getnode(2);
    root->right = getnode(3);
  //  root->left->left = getnode(4);
    root->left->right = getnode(4);
    root->left->right->left = getnode(5);
  //  root->right->left = getnode(6);
//    root->right->right = getnode(7);
    in(root);
    printf("\n");
    in_stack(root, st);
   free(st);

    return 0;
}
