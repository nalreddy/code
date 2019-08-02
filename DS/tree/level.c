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

struct Qnode 
{
 struct Qnode *next;
 struct Qnode *prev;
 struct TNode *root;
};

struct Queue
{
 struct Qnode *rear, *front;
 int q_size;
};

struct Qnode* getQnode(struct TNode *root)
{
 struct Qnode *temp = (struct Qnode *) malloc(sizeof(struct Qnode));
 if(!temp)
    return NULL;
 temp->next = NULL;
 temp->prev = NULL;
 temp->root = root;
 return temp;
}

void push(struct Queue *q, struct TNode *root)
{
  struct Qnode *cur = NULL;
  if(!q->rear) {
     q->rear = q->front = getQnode(root);
  } else {
     cur = getQnode(root);
     q->rear->next = cur;
     cur->prev = q->rear;
     q->rear = cur; 
  }

  q->q_size +=1;
}

void pop(struct Queue *q)
{
 struct Qnode *cur = NULL;

    if(!q->front) {
       printf("Queue is empty\n");
       return;
     }
     cur = q->front;
     q->front = cur->next;

     if(q->front) q->front->prev = NULL;     
     else {
        q->rear = q->front =  NULL;
     }
  
     q->q_size -=1;
     free(cur);
}

int  q_empty(struct Queue *q) 
{
  return (q->front == NULL) && (q->rear == NULL) ? 1 : 0;
}

struct TNode * rear(struct Queue *q)
{
 
 return q->rear->root;
}

struct TNode * front(struct Queue *q)
{
 return q->front->root;
}

void print_queue(struct Queue *q)
{
 struct Qnode *cur = NULL;

   if(!q->front) {
      printf(" nothing to print queue null\n");
      return;
   }
   cur = q->front;
   while(cur)
   {
     printf("%d  ", cur->root->data);
     cur = cur->next;
   }
}

int q_size(struct Queue *q)
{
 if(!q_empty(q)) return q->q_size;
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

void level(struct TNode *root, struct Queue *q)
{
 struct TNode *cur = NULL;

   if(!root)
       return;
   push(q, root);

   while(!q_empty(q))
   {
     cur = front(q);
     pop(q);
     printf("%d ", cur->data); 
     if(cur->left)
        push(q, cur->left); 
     if(cur->right)
        push(q, cur->right); 

   }
   
}

int main(){
    struct TNode *root = NULL;
//    in(root);
    struct Queue *q = (struct Queue *) malloc (sizeof(struct Queue));
    q->rear = NULL;
    q->front = NULL;
    q->q_size = 0;

    root = getnode(1);
    root->left = getnode(2);
#if 0
    root->right = getnode(3);
    root->left->left = getnode(4);
   // root->left->right = getnode(5);
    root->right->left = getnode(6);
   // root->right->right = getnode(7);
    push(q, root);
    push(q, root->left);
    push(q, root->right);
    push(q, root->left->left);
    push(q, root->left->right);
    push(q, root->right->left);
    push(q, root->right->right);
    print_queue(q);
    if(!q_empty(q))printf("front = %d and rear = %d size = %d\n",front(q)->data, rear(q)->data, q->q_size);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    push(q, root);
    print_queue(q);
    if(!q_empty(q))printf("front = %d and rear = %d size = %d\n",front(q)->data, rear(q)->data, q->q_size);
#endif    
    level(root, q);
    free(q);
    return 0;
}
