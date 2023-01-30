
// C++ program to add two numbers
// represented by linked list
#include <bits/stdc++.h>
using namespace std;

/* Linked list node */
class Node {
public:
	int data;
	Node* next;
};

/* Function to create a
new node with given data */
Node* newNode(int data)
{
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

/* Function to insert a node at the
beginning of the Singly Linked List */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = newNode(new_data);
	/* link the old list off the new node */
	new_node->next = (*head_ref);
	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Adds contents of two linked lists and
return the head node of resultant list */
Node* addTwoLists(Node* first, Node* second)
{
	// res is head node of the resultant list
	Node* res = NULL;
	Node *temp, *prev = NULL;
	int carry = 0, sum;

	// while both lists exist
	while (first != NULL || second != NULL) {
		// Calculate value of next digit in resultant list.
		// The next digit is sum of following things
		// (i) Carry
		// (ii) Next digit of first list (if there is a next digit)
		// (ii) Next digit of second list (if there is a next digit)
		sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
		// update carry for next calculation
		carry = (sum >= 10) ? 1 : 0;
		// update sum if it is greater than 10
		sum = sum % 10;
		// Create a new node with sum as data
		temp = newNode(sum);
		// if this is the first node then set it as head of the resultant list
		if (res == NULL)
			res = temp;
		// If this is not the first node then connect it to the rest.
		else
			prev->next = temp;
	
		// Set prev for next insertion
		prev = temp;

		// Move first and second pointers to next nodes
		if (first)
			first = first->next;
		if (second)
			second = second->next;
	}
	if (carry > 0)
		temp->next = newNode(carry);
	// return head of the resultant list
	return res;
}

Node* reverse(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	// reverse the rest list and put the first element at the end
	Node* rest = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	// fix the head pointer
	return rest;
}

// A utility function to print a linked list
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

/* Driver code */
int main(void)
{
	Node* res = NULL;
	Node* first = NULL;
	Node* second = NULL;

	// create first list 7->5->9->4->6
	push(&first, 6);
	push(&first, 4);
	push(&first, 9);
	push(&first, 5);
	push(&first, 7);
	printf("First list is ");
	printList(first);

	// create second list 8->4
	push(&second, 4);
	push(&second, 8);
	cout << "Second list is ";
	printList(second);

	// reverse both the lists
	first = reverse(first);
	second = reverse(second);
	// Add the two lists
	res = addTwoLists(first, second);

	// reverse the res to get the sum
	res = reverse(res);
	cout << "Resultant list is ";
	printList(res);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/* Linked list Node */
struct Node {
	int data;
	struct Node* next;
};

Node* newNode(int data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

/* Function to insert a node at the
beginning of the Singly Linked List */
void push(Node** head_ref, int new_data){
	/* allocate node */
	Node* new_node = newNode(new_data);
	/* link the old list off the new node */
	new_node->next = (*head_ref);
	/* move the head to point to the new node */
	(*head_ref) = new_node;
}
// function to linked list
void printList(Node* n){
	while (n) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}
// function that work on addition operation.
Node* addTwoLists(Node*first , Node*second){
int num1=0,num2=0;
//here we get num1 form first linked list.
while(first->next!=NULL){
	num1 +=first->data;
	num1*=10;
	first=first->next;
}
num1+=first->data;
// here we get num2 form second linked list.
while(second->next!=NULL){
	num2 +=second->data;
	num2*=10;
	second=second->next;
}
num2+=second->data;
// here we add both number.
int num3=num1+num2;
Node* temp=NULL;
//Node* result=temp;
// convert num3 into linked list.
while(num3!=0){
	int last=num3%10;
	push(&temp,last);
	num3=num3/10;
}
// finally return resultant linked list.
return temp;
}
int main() {
Node* first = NULL;
Node* second = NULL;
	push(&first, 6);
	push(&first, 4);
	push(&first, 9);
	push(&first, 5);
	push(&first, 7);

	push(&second, 4);
	push(&second, 8);

	Node* ans = addTwoLists(first, second);

	cout << "Sum is : ";
	printList(ans);
return 0;
}
// C++ program to add two numbers represented by Linked
// Lists using Stack
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};

Node* newnode(int data)
{
	Node* x = new Node();
	x->data = data;
	return x;
}

// function that returns the sum of two numbers represented
// by linked lists
Node* addTwoNumbers(Node* l1, Node* l2)
{
	Node* prev = NULL;
	// Create 3 stacks
	stack<Node*> s1, s2, s3;
	// Fill first stack with first List Elements
	while (l1 != NULL) {
		s1.push(l1);
		l1 = l1->next;
	}
	// Fill second stack with second List Elements
	while (l2 != NULL) {
		s2.push(l2);
		l2 = l2->next;
	}
	int carry = 0;
	// Fill the third stack with the sum of first and second
	// stack
	while (!s1.empty() && !s2.empty()) {
		int sum = s1.top()->data + s2.top()->data + carry;
		Node* temp = newnode(sum % 10);
		s3.push(temp);
		if (sum > 9) {
			carry = 1;
		}
		else {
			carry = 0;
		}
		s1.pop();
		s2.pop();
	}
	while (!s1.empty()) {
		int sum = carry + s1.top()->data;
		Node* temp = newnode(sum % 10);
		s3.push(temp);
		if (sum > 9) {
			carry = 1;
		}
		else {
			carry = 0;
		}
		s1.pop();
	}
	while (!s2.empty()) {
		int sum = carry + s2.top()->data;
		Node* temp = newnode(sum % 10);
		s3.push(temp);
		if (sum > 9) {
			carry = 1;
		}
		else {
			carry = 0;
		}
		s2.pop();
	}
	// If carry is still present create a new node with
	// value 1 and push it to the third stack
	if (carry == 1) {
		Node* temp = newnode(1);
		s3.push(temp);
	}
	// Link all the elements inside third stack with each
	// other
	if (!s3.empty())
		prev = s3.top();
	while (!s3.empty()) {
		Node* temp = s3.top();
		s3.pop();
		if (s3.size() == 0) {
			temp->next = NULL;
		}
		else {
			temp->next = s3.top();
		}
	}
	return prev;
}

// utility functions
// Function that displays the List
void Display(Node* head)
{
	if (head == NULL) {
		return;
	}
	while (head->next != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << head->data << endl;
}

// Function that adds element at the end of the Linked List
void push(Node** head_ref, int d)
{
	Node* new_node = newnode(d);
	new_node->next = NULL;
	if (*head_ref == NULL) {
		new_node->next = *head_ref;
		*head_ref = new_node;
		return;
	}
	Node* last = *head_ref;
	while (last->next != NULL && last != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return;
}
// Driver Program for above Functions
int main()
{
	// Creating two lists
	// first list = 9 -> 5 -> 0
	// second List = 6 -> 7
	Node* first = NULL;
	Node* second = NULL;
	Node* sum = NULL;
	push(&first, 7);
	push(&first, 5);
	push(&first, 9);
	push(&first, 4);
	push(&first, 6);
	push(&second, 8);
	push(&second, 4);
	cout << "First List : ";
	Display(first);
	cout << "Second List : ";
	Display(second);
	sum = addTwoNumbers(first, second);
	cout << "Sum List : ";
	Display(sum);
	return 0;
}
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

// recursive function
Node* addition(Node* temp1, Node* temp2, int size1,
			int size2)
{
	// creating a new Node
	Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));

	// base case
	if (temp1->next == NULL && temp2->next == NULL) {
		// addition of current nodes which is the last nodes
		// of both linked lists
		newNode->data = (temp1->data + temp2->data);

		// set this current node's link null
		newNode->next = NULL;

		// return the current node
		return newNode;
	}

	// creating a node that contains sum of previously added
	// number
	Node* returnedNode
		= (struct Node*)malloc(sizeof(struct Node));

	// if sizes are same then we move in both linked list
	if (size2 == size1) {
		// recursively call the function
		// move ahead in both linked list
		returnedNode = addition(temp1->next, temp2->next,
								size1 - 1, size2 - 1);

		// add the current nodes and append the carry
		newNode->data = (temp1->data + temp2->data)
						+ ((returnedNode->data) / 10);
	}
	// or else we just move in big linked list
	else {
		// recursively call the function
		// move ahead in big linked list
		returnedNode = addition(temp1, temp2->next, size1,
								size2 - 1);

		// add the current node and carry
		newNode->data
			= (temp2->data) + ((returnedNode->data) / 10);
	}

	// this node contains previously added numbers
	// so we need to set only rightmost digit of it
	returnedNode->data = (returnedNode->data) % 10;

	// set the returned node to the current node
	newNode->next = returnedNode;

	// return the current node
	return newNode;
}

// Function to add two numbers represented by nexted list.
struct Node* addTwoLists(struct Node* head1,
						struct Node* head2)
{
	struct Node *temp1, *temp2, *ans = NULL;

	temp1 = head1;
	temp2 = head2;

	int size1 = 0, size2 = 0;

	// calculating the size of first linked list
	while (temp1 != NULL) {
		temp1 = temp1->next;
		size1++;
	}
	// calculating the size of second linked list
	while (temp2 != NULL) {
		temp2 = temp2->next;
		size2++;
	}

	Node* returnedNode
		= (struct Node*)malloc(sizeof(struct Node));

	// traverse the bigger linked list
	if (size2 > size1) {
		returnedNode = addition(head1, head2, size1, size2);
	}
	else {
		returnedNode = addition(head2, head1, size2, size1);
	}

	// creating new node if head node is >10
	if (returnedNode->data >= 10) {
		ans = (struct Node*)malloc(sizeof(struct Node));
		ans->data = (returnedNode->data) / 10;
		returnedNode->data = returnedNode->data % 10;
		ans->next = returnedNode;
	}
	else
		ans = returnedNode;

	// return the head node of linked list that contains
	// answer
	return ans;
}

void Display(Node* head)
{
	if (head == NULL) {
		return;
	}
	while (head->next != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << head->data << endl;
}
// Function that adds element at the end of the Linked List
void push(Node** head_ref, int d)
{
	Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));
	new_node->data = d;
	new_node->next = NULL;
	if (*head_ref == NULL) {
		new_node->next = *head_ref;
		*head_ref = new_node;
		return;
	}
	Node* last = *head_ref;
	while (last->next != NULL && last != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return;
}
// Driver Program for above Functions
int main()
{
	// Creating two lists
	Node* first = NULL;
	Node* second = NULL;
	Node* sum = NULL;
	push(&first, 7);
	push(&first, 5);
	push(&first, 9);
	push(&first, 4);
	push(&first, 6);
	push(&second, 8);
	push(&second, 4);
	cout << "First List : ";
	Display(first);
	cout << "Second List : ";
	Display(second);
	sum = addTwoLists(first, second);
	cout << "Sum List : ";
	Display(sum);
	return 0;
}

// This code is contributed by Dharmik Parmar
// C++ Code to add two nodes by reversing the two lists

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
	int data;
	struct Node* next;
};

Node* newNode(int data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

/* Function to insert a node at the
beginning of the Singly Linked List */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = newNode(new_data);
	/* link the old list off the new node */
	new_node->next = (*head_ref);
	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

void printList(Node* n)
{
	while (n) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

struct Node* reverseList(struct Node* list)
{
	Node *prev = NULL, *cur = list, *next = NULL;
	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

//----------------------------------------------------------------------------

Node* addTwoLists(Node* first, Node* second)
{
	// code here
	first = reverseList(first);
	second = reverseList(second);

	int carry = 0;
	Node *head = NULL, *prev = NULL;
	Node* sum = NULL;
	// if any one of these is left we are still left with addition
	while (first != NULL or second != NULL or carry == 1)
	{
		int newVal = carry;
		if (first)
			newVal += first->data;
		if (second)
			newVal += second->data;
		// to be used in the next node calculation
		carry = newVal / 10;
		newVal = newVal % 10;
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = newVal;
		// appending in the beginning of the final ans list,
		// this way we do not have to reverse in the end
		newNode->next = sum;
		sum = newNode;
		// initialising nodes for next iteration

		if (first)
			first = first->next;
		if (second)
			second = second->next;
	}

	return sum;
}

//----------------------------------------------------------------------------

// { Driver Code Starts.

int main()
{
	Node* first = NULL;
	Node* second = NULL;

	push(&first, 6);
	push(&first, 4);
	push(&first, 9);
	push(&first, 5);
	push(&first, 7);

	push(&second, 4);
	push(&second, 8);

	Node* ans = addTwoLists(first, second);

	cout << "Sum is : ";
	printList(ans);

	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)

