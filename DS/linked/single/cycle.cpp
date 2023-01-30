// C++ program to detect loop in a linked list 
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = new Node; 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list of the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

// Returns true if there is a loop in linked list 
// else returns false. 
bool detectLoop(struct Node* h) 
{ 
	unordered_set<Node*> s; 
	while (h != NULL) { 
		// If this node is already present 
		// in hashmap it means there is a cycle 
		// (Because you will be encountering the 
		// node for the second time). 
		if (s.find(h) != s.end()) 
			return true; 

		// If we are seeing the node for 
		// the first time, insert it in hash 
		s.insert(h); 

		h = h->next; 
	} 

	return false; 
} 

/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 

	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 10); 

	/* Create a loop for testing */
	head->next->next->next->next = head; 

	if (detectLoop(head)) 
		cout << "Loop Found"; 
	else
		cout << "No Loop"; 

	return 0; 
} 
// This code is contributed by Geetanjali

// C++ program to detect loop in a linked list 
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
	int flag; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = new Node; 

	/* put in the data */
	new_node->data = new_data; 

	new_node->flag = 0; 

	/* link the old list of the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

// Returns true if there is a loop in linked list 
// else returns false. 
bool detectLoop(struct Node* h) 
{ 
	while (h != NULL) { 
		// If this node is already traverse 
		// it means there is a cycle 
		// (Because you we encountering the 
		// node for the second time). 
		if (h->flag == 1) 
			return true; 

		// If we are seeing the node for 
		// the first time, mark its flag as 1 
		h->flag = 1; 

		h = h->next; 
	} 

	return false; 
} 

/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 

	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 10); 

	/* Create a loop for testing */
	head->next->next->next->next = head; 

	if (detectLoop(head)) 
		cout << "Loop Found"; 
	else
		cout << "No Loop"; 

	return 0; 
} 
// This code is contributed by Geetanjali

// C++ program to detect loop in a linked list 
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
class Node { 
public: 
	int data; 
	Node* next; 
}; 

void push(Node** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node = new Node(); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list of the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

int detectLoop(Node* list) 
{ 
	Node *slow_p = list, *fast_p = list; 

	while (slow_p && fast_p && fast_p->next) { 
		slow_p = slow_p->next; 
		fast_p = fast_p->next->next; 
		if (slow_p == fast_p) { 
			return 1; 
		} 
	} 
	return 0; 
} 

/* Driver code*/
int main() 
{ 
	/* Start with the empty list */
	Node* head = NULL; 

	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 10); 

	/* Create a loop for testing */
	head->next->next->next->next = head; 
	if (detectLoop(head)) 
		cout << "Loop Found"; 
	else
		cout << "No Loop"; 
	return 0; 
} 

// This is code is contributed by rathbhupendra
// C++ program to return first node of loop 
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int key; 
	struct Node* next; 
}; 

Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->next = NULL; 
	return temp; 
} 

// A utility function to print a linked list 
void printList(Node* head) 
{ 
	while (head != NULL) { 
		cout << head->key << " "; 
		head = head->next; 
	} 
	cout << endl; 
} 

// Function to detect first node of loop 
// in a linked list that may contain loop 
bool detectLoop(Node* head) 
{ 
	// Create a temporary node 
	Node* temp = new Node; 
	while (head != NULL) { 
		// This condition is for the case when there is no 
		// loop 
		if (head->next == NULL) 
			return false; 
		// Check if next is already pointing to temp 
		if (head->next == temp) 
			return true; 
		// Store the pointer to the next node 
		// in order to get to it in the next step 
		Node* next = head->next; 
		// Make next point to temp 
		head->next = temp; 
		// Get to the next node in the list 
		head = next; 
	} 
	return false; 
} 

/* Driver program to test above function*/
int main() 
{ 
	Node* head = newNode(1); 
	head->next = newNode(2); 
	head->next->next = newNode(3); 
	head->next->next->next = newNode(4); 
	head->next->next->next->next = newNode(5); 
	/* Create a loop for testing(5 is pointing to 3) */
	head->next->next->next->next->next = head->next->next; 
	bool found = detectLoop(head); 
	if (found) 
		cout << "Loop Found"; 
	else
		cout << "No Loop"; 
	return 0; 
} 

// This code is contributed by Aditya Kumar (adityakumar129)
// C++ program to return first node of loop 
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int key; 
	struct Node* next; 
}; 

Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->next = NULL; 
	return temp; 
} 

// A utility function to print a linked list 
void printList(Node* head) 
{ 
	while (head != NULL) { 
		cout << head->key << " "; 
		head = head->next; 
	} 
	cout << endl; 
} 

/*returns distance between first and last node every time 
* last node moves forwards*/
int distance(Node* first, Node* last) 
{ 
	/*counts no of nodes between first and last*/
	int counter = 0; 

	Node* curr; 
	curr = first; 

	while (curr != last) { 
		counter += 1; 
		curr = curr->next; 
	} 

	return counter + 1; 
} 

// Function to detect first node of loop 
// in a linked list that may contain loop 
bool detectLoop(Node* head) 
{ 

	// Create a temporary node 
	Node* temp = new Node; 

	Node *first, *last; 

	/*first always points to head*/
	first = head; 
	/*last pointer initially points to head*/
	last = head; 

	/*current_length stores no of nodes between current 
	* position of first and last*/
	int current_length = 0; 

	/*prev_length stores no of nodes between previous 
	* position of first and last*/
	int prev_length = -1; 

	while (current_length > prev_length && last != NULL) { 
		// set prev_length to current length then update the 
		// current length 
		prev_length = current_length; 
		// distance is calculated 
		current_length = distance(first, last); 
		// last node points the next node 
		last = last->next; 
	} 

	if (last == NULL) { 
		return false; 
	} 
	else { 
		return true; 
	} 
} 

/* Driver program to test above function*/
int main() 
{ 
	Node* head = newNode(1); 
	head->next = newNode(2); 
	head->next->next = newNode(3); 
	head->next->next->next = newNode(4); 
	head->next->next->next->next = newNode(5); 

	/* Create a loop for testing(5 is pointing to 3) */
	head->next->next->next->next->next = head->next->next; 

	bool found = detectLoop(head); 
	if (found) 
		cout << "Loop Found"; 
	else
		cout << "No Loop Found"; 

	return 0; 
} 
// C++ program to return first node of loop 
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int key; 
	struct Node* next; 
}; 

Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->next = NULL; 
	return temp; 
} 

// Function to detect first node of loop 
// in a linked list that may contain loop 
bool detectLoop(Node* head) 
{ 

	// If the head is null we will return false 
	if (!head) 
		return 0; 
	else { 

		// Traversing the linked list 
		// for detecting loop 
		while (head) { 
			// If loop found 
			if (head->key == -1) { 
				return true; 
			} 

			// Changing the data of visited node to any 
			// value which is outside th given range here it 
			// is supposed the given range is (1 <= Data on 
			// Node <= 10^3) 
			else { 
				head->key = -1; 
				head = head->next; 
			} 
		} 
		// If loop not found return false 
		return 0; 
	} 
} 

public static boolean hasLoop(Node root) {
    if (root == null) return false;
    
    Node slow = root, fast = root;
    int taken = 0, limit = 2;
    
    while (fast.next != null) {
        fast = fast.next;
        taken++;
        if (slow == fast) return true;
        
        if (taken == limit) {
            taken = 0;
            limit <<= 1;    // equivalent to limit *= 2;
            slow = fast;    // teleporting the turtle (to the hare's position) 
        }
    }
    return false;
}
/* Driver program to test above function*/
int main() 
{ 
	Node* head = newNode(1); 
	head->next = newNode(2); 
	head->next->next = newNode(3); 
	head->next->next->next = newNode(4); 
	head->next->next->next->next = newNode(5); 

	/* Create a loop for testing(5 is pointing to 3) */
	head->next->next->next->next->next = head->next->next; 

	bool found = detectLoop(head); 
	cout << (found ? "Loop Found" : "Not Found") << endl; 
	return 0; 
}

