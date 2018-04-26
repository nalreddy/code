#include<stdio.h>
#include<stdlib.h>

struct link
{
 struct link *next;
 struct link *prev;
 int data;
};

struct link * getnode(int x)
{
 struct link *temp = 
     (struct link *) malloc(sizeof(struct link));

 temp->next = NULL;
 temp->prev = NULL;
 temp->data = x;
 return temp;
}



struct link ** 
insert_atfront(struct link **head, int data)
{
  struct link *cur = getnode(data);

  if(*head == NULL) {
     *head = cur; 
     return head;
  }

  cur->next = *head;
  (*head)->prev = cur;
  *head = cur;

  return head;
}

void printlist(struct link *head)
{
    if(!head)
	return;
   while(head) {
      printf("%d ",head->data);
      head = head->next;
   } 
   printf("\n");
}

void delete_node(struct link **head, int key) 
{
    struct link *cur = NULL;

    if((head == NULL) && (*head == NULL )) return;
    
    cur = *head;
    while (cur) 
    {
        if(cur == (*head) && (cur->data == key) ) {
            if (cur->next) {
               *head= cur->next;
               (*head)->prev = NULL;
            } else {
               *head = NULL;
            }
            free(cur);
            break;
        } else if ( cur->data == key ) {
            if(cur->next) {
                cur->next->prev = cur->prev;
                cur->prev->next = cur->next;
            } else {
                cur->prev->next = NULL;
            }
            free(cur);
            break;
        }
        cur = cur->next;
    }
}

void deletelink(struct link **head){
    struct link *temp = NULL;
    if(!*head)
	return;
    temp = *head;
    while(*head) {
      temp = *head;
      free(temp);
      *head = (*head)->next;
    }
}

int main()
{
    struct link *head = NULL;
    int i = 0;
    for ( i = 0; i < 5 ; i++) {
        insert_atfront(&head, i);
    }

    printlist(head);

    delete_node(&head, 0);
    printlist(head);
   return 0;
}
