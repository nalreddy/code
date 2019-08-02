//#include<pthread.h>
#include "array_stack.h"

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
    printf("peek = top = %d  %d\n",st->top, peek(st));
    pop(st);
    free(st->array);
    free(st);

    printf("peek = top = %d  %d\n",st->top, peek(st));
    if(!st)
        printf("memory freed\n");

    return 0;
}
