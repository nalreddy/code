#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data);

/*This solution uses the temporary
dummy to build up the result list */
Node* sortedIntersect(Node* a, Node* b)
{
	Node dummy;
	Node* tail = &dummy;
	dummy.next = NULL;

	/* Once one or the other
	list runs out -- we're done */
	while (a != NULL && b != NULL) {
		if (a->data == b->data) {
			push((&tail->next), a->data);
			tail = tail->next;
			a = a->next;
			b = b->next;
		}
		/* advance the smaller list */
		else if (a->data < b->data)
			a = a->next;
		else
			b = b->next;
	}
	return (dummy.next);
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at
the beginning of the linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = (Node*)malloc(
		sizeof(Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list of the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in
a given linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data <<" ";
		node = node->next;
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty lists */
	Node* a = NULL;
	Node* b = NULL;
	Node* intersect = NULL;

	/* Let us create the first sorted
	linked list to test the functions
	Created linked list will be
	1->2->3->4->5->6 */
	push(&a, 6);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);

	/* Let us create the second sorted linked list
Created linked list will be 2->4->6->8 */
	push(&b, 8);
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);

	/* Find the intersection two linked lists */
	intersect = sortedIntersect(a, b);

	cout<<"Linked list containing common items of a & b \n";
	printList(intersect);
}

// C++ program to implement above approach
#include <bits/stdc++.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** head_ref,
		int new_data);

/* This solution uses the local reference */
struct Node* sortedIntersect(
	struct Node* a,
	struct Node* b)
{
	struct Node* result = NULL;
	struct Node** lastPtrRef = &result;

	/* Advance comparing the first
	nodes in both lists.
	When one or the other list runs
	out, we're done. */
	while (a != NULL && b != NULL) {
		if (a->data == b->data) {
			/* found a node for the intersection */
			push(lastPtrRef, a->data);
			lastPtrRef = &((*lastPtrRef)->next);
			a = a->next;
			b = b->next;
		}
		else if (a->data < b->data)
			a = a->next; /* advance the smaller list */
		else
			b = b->next;
	}
	return (result);
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the
beginning of the linked list */
void push(struct Node** head_ref,
		int new_data)
{
	/* allocate node */
	struct Node* new_node = (struct Node*)malloc(
		sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list of the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty lists */
	struct Node* a = NULL;
	struct Node* b = NULL;
	struct Node* intersect = NULL;

	/* Let us create the first sorted
	linked list to test the functions
Created linked list will be
1->2->3->4->5->6 */
	push(&a, 6);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);

	/* Let us create the second sorted linked list
Created linked list will be 2->4->6->8 */
	push(&b, 8);
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);

	/* Find the intersection two linked lists */
	intersect = sortedIntersect(a, b);

	printf("\n Linked list containing common items of a & b \n ");
	printList(intersect);

	return 0;
}

//This code is contributed by Abhijeet Kumar(abhijeet19403)
#include <bits/stdc++.h>
using namespace std;

// Link list node
struct Node
{
	int data;
	struct Node* next;
};

struct Node* sortedIntersect(struct Node* a,
							struct Node* b)
{
	
	// base case
	if (a == NULL || b == NULL)
		return NULL;

	/* If both lists are non-empty */

	/* Advance the smaller list and
	call recursively */
	if (a->data < b->data)
		return sortedIntersect(a->next, b);

	if (a->data > b->data)
		return sortedIntersect(a, b->next);

	// Below lines are executed only
	// when a->data == b->data
	struct Node* temp = (struct Node*)malloc(
				sizeof(struct Node));
	temp->data = a->data;

	// Advance both lists and call recursively
	temp->next = sortedIntersect(a->next,
								b->next);
	return temp;
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at
the beginning of the linked list */
void push(struct Node** head_ref, int new_data)
{
	
	/* Allocate node */
	struct Node* new_node = (struct Node*)malloc(
					sizeof(struct Node));

	/* Put in the data */
	new_node->data = new_data;

	/* Link the old list of the new node */
	new_node->next = (*head_ref);

	/* Move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in
a given linked list */
void printList(struct Node* node)
{
	while (node != NULL)
	{
		cout << " " << node->data;
		node = node->next;
	}
}

// Driver code
int main()
{
	
	/* Start with the empty lists */
	struct Node* a = NULL;
	struct Node* b = NULL;
	struct Node* intersect = NULL;

	/* Let us create the first sorted
	linked list to test the functions
	Created linked list will be
	1->2->3->4->5->6 */
	push(&a, 6);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);

	/* Let us create the second sorted linked list
	Created linked list will be 2->4->6->8 */
	push(&b, 8);
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);

	/* Find the intersection two linked lists */
	intersect = sortedIntersect(a, b);

	cout << "\n Linked list containing "
		<< "common items of a & b \n ";
	printList(intersect);

	return 0;
}

// This code is contributed by shivanisinghss2110

// C++ program to implement above approach
#include <bits/stdc++.h>
using namespace std;

// Link list node
struct Node {
	int data;
	struct Node* next;
};
void printList(struct Node* node)
{
	while (node != NULL) {
		cout << " " << node->data;
		node = node->next;
	}
}

void append(struct Node** head_ref, int new_data)
{

	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}
vector<int> intersection(struct Node* tmp1, struct Node* tmp2,
				int k)
{
	vector<int> res(k);
	unordered_set<int> set;
	while (tmp1 != NULL) {

		set.insert(tmp1->data);
		tmp1 = tmp1->next;
	}

	int cnt = 0;

	while (tmp2 != NULL) {
		if (set.find(tmp2->data) != set.end()) {
			res[cnt] = tmp2->data;
			cnt++;
		}
		tmp2 = tmp2->next;
	}

	return res;
}

// Driver code
int main()
{

	struct Node* ll = NULL;
	struct Node* ll1 = NULL;

	append(&ll,7);
	append(&ll,6);
	append(&ll,5);
	append(&ll,4);
	append(&ll,3);
	append(&ll,2);
	append(&ll,1);
	append(&ll,0);

	append(&ll1,7);
	append(&ll1,6);
	append(&ll1,5);
	append(&ll1,4);
	append(&ll1,3);
	append(&ll1,12);
	append(&ll1,0);
	append(&ll1,9);

	vector<int> arr= intersection(ll, ll1, 6);

	for (int i :arr)
		cout << i << "\n";

	return 0;
}

// This code is contributed by Abhijeet Kumar(abhijeet19403)

