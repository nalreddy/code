#include<stdio.h>
#include<stdlib.h>


struct link
{
 struct link *next;
 int data;
};

struct link * getnode(int x)
{
 struct link *temp = 
     (struct link *) malloc(sizeof(struct link));

 temp->next = NULL;
 temp->data = x;
 return temp;
}

int get_count(struct link *head)
{
   int c = 0;
   struct link *cur = head;

   while(cur) 
   {
       c++;
       cur = cur->next;
   }
   return c;
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

void reverse(struct link **head)
{

    struct link *cur = *head;
    struct link *next;
    struct link *prev = NULL;

    while(cur) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    *head = prev;
}

void k_reverse(struct link **head, int k) {
 

}

void mid(struct link *head) {
    struct link *slow = head, *fast = head;

    if(head == NULL)
	printf("null \n");

    while(slow && fast && fast->next) {
          slow = slow->next;
	  fast = fast->next->next;
    }
    printf("len = %d\n", slow->data);
}

int find_loop(struct link *head) {
     struct link *slow = head, *fast ;

     if(head == NULL) 
	 return 0;

     fast = head->next;

     while(slow && fast && fast->next && fast->next->next) {
   
	  if(slow == fast) return 1;
	  slow = slow->next;
	  fast = fast->next->next;
     }

     return 0;
}

void intersect(struct link *head1, struct link *head2)
{
    int l1 = 0, l2 = 0;
    l1 = get_count(head1);
    l2 = get_count(head2);
    int d = 0;
    struct link *temp = NULL;
    struct link *cur1 = head1, *cur2 = head2;

    if(l1 > l2) {
        d = l1 - l2;
        while(d) {cur1 = cur1->next ; d--; }	
     }	else {
        d = l2 - l1;
        while(d) {cur2 = cur2->next ; d--; }	
     }

     while(cur1 && cur2) {

	 if(cur1 == cur2) {  printf("intersect at %d \n", cur1->data); return;}
	 cur1 = cur1->next;
	 cur2 = cur2->next;
     }

     printf("not intersecting \n");
}

void movenode(struct link **src, struct link **dst)
{
    struct link *next = *src;
   
    *src = *src->next;
    *dst->next = next;
    *dst = *dst->next;      
}

struct next * merge(struct link *a, struct link *b)
{
    struct link dummy;
    struct link *tail = &dummy;
    dummy.next = NULL;
    struct link *cur = NULL;

    while(a || b)
    {
	if(!a)
	    tail->next = a;
	if(!b)
	    tail->next = b;
	if(a->data < b->data) {
           movenode(&a,&tail->next) 

	 }else if(a->data > b->data) {
           movenode(&b,&tail->next) 
	 } else {
           movenode(&a,&tail->next) 
           cur = b;
	   b = b->next;
	   free(cur);
	 }
	tail = tail->next;
    }

    return dummy.next;
}
void flat(struct link *head) {



}
//add_linklists
//merge
//remove_loop
//find_intersection

int main(){
#if 0    
   struct link *head = NULL;
   head = getnode(10);
    head->next = getnode(11);
    head->next->next = getnode(12);
    head->next->next->next = getnode(13);
    head->next->next->next->next = getnode(14);
#endif    
    struct link *head1 = NULL;
    struct link *head2 = NULL;
 
    head1 = getnode(10);
    head1->next = getnode(11);
    head1->next->next = getnode(12);
    head1->next->next->next = getnode(13);
    head1->next->next->next->next = getnode(14);
    head1->next->next->next->next->next = getnode(16);
    head2 = getnode(1);
    head2->next = getnode(2);
    head2->next->next = getnode(3);
    head2->next->next->next = getnode(4);
    head2->next->next->next->next = head1->next->next->next;

    printlist(head1);
    printlist(head2);
//    intersect(head2,head1);
    struct link *temp = merge(head1,head2);
    return 0;
}
