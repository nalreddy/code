#include<stdio.h>
#include<stdlib.h>

struct queue 
{
 int capacity;
 int rear,front;
 int *array;
};

int 
create_queue(struct queue **st, int capacity)
{
    //int ret = 0;
   *st = (struct queue *) malloc(sizeof(struct queue));
   //error check
   (*st)->rear = ;
   (*st)->front = -1;
   (*st)->capacity = capacity;
   (*st)->array = (void *)malloc(sizeof(int) * capacity);
   //error check
   return 0;
}

int 
isEmpty(struct queue *st)
{
  return (st->front == -1 )&& (st->rear == -1);   
}

int
isFull(struct queue *st)
{
    return st->front == ((st->rear + 1) % st->capacity);
}

int enqueu(struct queue *st, int x)
{
    if(isFull(st)) {
       printf("stack full\n");
       return -1;
    }
    if(st->rear == -1)
	st->front = -1;

    st->rear = ((st->rear + 1) % st->capacity);
    st->array[st->st->rear] = x;
 return 0; 
}

int pop(struct stack *st)
{
   int temp;
   if(isEmpty(st)) {
      printf("stack empty\n");
      return -1;
   }   
  temp = st->array[st->front];

  st->front = ((st->front + 1) % st->capacity);

  return temp;
}
#if 0
int peek(struct stack *st)
{
 return st->array[st->top];
}
#endif
int main()
{
    int ret = 0;
    struct queue *st = NULL;
    ret = create_queue( &st, 10);
    if(!st)
	printf("no memory\n");
    else
	printf("stack capacity = %d\n", st->capacity);
  return 0;
}
