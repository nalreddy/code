#include<stdio.h>
#include<stdlib.h>

struct stack
{
 int capacity;
 int top;
 int *array;
};

int
create_stack(struct stack **st, int capacity)
{
    //int ret = 0;
   *st = (struct stack *) malloc(sizeof(struct stack));
   //error check
   (*st)->top = -1;
   (*st)->capacity = capacity;
   (*st)->array = (int *)malloc(sizeof(int) * capacity);
   //error check
   return 0;
}

int
isEmpty(struct stack *st)
{
  return st->top == -1;
}

int
isFull(struct stack *st)
{
    return st->top == st->capacity - 1;
}

int push(struct stack *st, int x)
{
    if(isFull(st)) {
       printf("stack full\n");
       return -1;
    }
    st->top +=1;
    st->array[st->top] = x;
    printf("push %d \n", x);
 return 0;
}

int pop(struct stack *st)
{
   int temp;
   if(isEmpty(st)) {
      printf("stack empty\n");
      return -1;
   }
  temp = st->array[st->top];
  st->top -=1;
  printf(" pop  = %d \n" , temp);

  return temp;
}

int peek(struct stack *st)
{
 return st->array[st->top];
}
