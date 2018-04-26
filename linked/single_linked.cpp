#include<iostream>

using namespace std;

typedef struct node 
{
    int data;
    struct node *next;
} node;
   

class list 
{
    public:

        list() { head = NULL; }
        void add_node(int x);
        void delete_list()
        void printlist();

    private :
        node* head;
        node* getnode(int x);
};
 

void list :: printlist()
{
    node *cur = head;
    if(!cur) {
        cout << "empty list " << endl;
        return;
    }
    while(cur) {
        cout << cur->data << " ";
        cur = cur->next;
    } 
    cout << endl;
}

int get_count()
{
   node* cur = head;

   while(cur) 
   {
       c++;
       cur = cur->next;
   }
   return c;
}

node* list :: getnode(int x)
{
    node* temp = new node;

    if( !temp ) return NULL;

    temp->next = NULL;
    temp->data = x;

    return temp;
}

//error handling , out of memory
void list :: add_node(int x)
{
    node* temp = NULL;
    int error = 0;

    if (head == NULL) {
        head = getnode(x);
        return;
    }

    temp = getnode(x);
    temp->next = head;
    head = temp;

    return;
}

void list :: delete_list()
{
    node* cur = head, temp = NULL;
    if(!head) {
        cout << "List empty , nothing to delete " << endl;
	return;
    }

    while(cur) {
      temp = cur;
      cur = cur->next;
      free(temp);
    }
    head = NULL;
}

#if 0
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

#endif

int main(){
    list l;

    l.printlist();
    l.add_node(11);
    l.add_node(12);
    l.add_node(13);
    l.add_node(14);
    l.printlist();

    l.delete_list();
    return 0;
}
