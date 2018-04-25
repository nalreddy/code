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
   (*st)->array = (void *)malloc(sizeof(int) * capacity);
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
  return temp;
}

int peek(struct stack *st)
{
 return st->array[st->top];
}

int main()
{
    int ret = 0;
    struct stack *st = NULL;
    ret = create_stack( &st, 10);
    if(!st)
	printf("no memory\n");
    else
	printf("stack capacity = %d\n", st->capacity);
    push(st,3);
    push(st,5);
    printf("peek = top = %d  %d\n",st->top, peek(st));
    printf("peek = top = %d  %d\n",st->top, peek(st));
    pop(st);
    pop(st);
    printf("peek = top = %d  %d\n",st->top, peek(st));
    free(st->array);
    free(st);

    printf("peek = top = %d  %d\n",st->top, peek(st));
    if(!st)
	printf("memory freed\n");
  return 0;
}
