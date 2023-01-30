#include<iostream>
#include<stack>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node() 
		{
		}
		Node(int data)
		{
		this->data = data;
		this->next = nullptr;
		}
};

void printlist(Node* head)
{
	if (head == nullptr)
	{
		std::cout << "Nothing to print , list is empty \n";
		return;
	}

	while (head != nullptr)
	{
		std::cout << head->data << " "; 
		head = head->next;
	}

	std::cout << std::endl;
}

void appendAtFront(Node** head, int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

void appendAfter(Node* prev_node, int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = nullptr;
	if ( prev_node == nullptr)
	{
		cout << "Error previous node can not be null" << endl;
		return;
	}
	temp->next = prev_node->next;
	prev_node->next = temp;

	return;

}
void appendAtLast(Node** head, int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = nullptr;

	Node* last = *head;

	if (*head == nullptr) {
		*head = temp;
		return; 
	}

	while (last->next != nullptr) {
		last = last->next;
	}

	last->next = temp;
	return;
}

void insertAtPos(Node* head, int data, int pos)
{
	Node* temp = new Node();
	Node* prev_node = head;
	int i = 1;
	temp->data = data;
	temp->next = nullptr;	

	while(i < pos && head != nullptr)
	{
		i++;
		prev_node = head;
		head = head->next;
	}	
	prev_node->next = temp;
	temp->next = head;
}

void deleteList(Node** head)
{
	Node* temp = nullptr;

	while(*head)
	{
		temp = *head;
		*head = (*head)->next;
		delete temp;
	}
}

void deleteAtFront(Node** head) 
{
	Node* temp = *head;

	if (head == nullptr)
	{
		std::cout << "Nothing to delete \n";
		return;
	}

	*head = (*head)->next;
	delete temp;
}

void deleteAtBack(Node** head)
{
	Node* temp = *head;

	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	delete temp;
}

void deleteAtPos(Node** head, int pos)
{
	Node* temp = *head;
	Node* prev_node;
	int i = 1;

	if (*head == nullptr)
	{
		std::cout << "Nothing to delete \n";
		return;
	}

	if (pos == 1)
	{
		*head = (*head)->next;
		return;
	}
	while (i < pos && temp != nullptr)
	{
		i++;
		prev_node = temp;
		temp = temp->next;
	}
	prev_node->next = temp->next;
	delete temp;
}
// Nth node from end of the list

void nthnodefromend(Node* head, int pos)
{

	Node* fast = head;
	Node* slow = head;

	for (int i = 1; i < pos; i++)
	{
		if (fast == nullptr )
		{
			cout << " Position is out of range \n";
			return;
		}
		fast = fast->next;
	}

	while (fast->next != nullptr)
	{
		fast = fast->next;
		slow = slow->next;
	}
	cout << "Slow ptr  " << slow->data << endl;
	return;
}
// middle of linked list
void listmiddle(Node* head)
{
	Node* fast = head;
	Node* slow = head;

	while ( fast != nullptr && fast->next != nullptr) 
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	cout << "middle element " << slow->data << endl;
}

// remove duplicates sorted list
void removeDuplicatesSortedList(Node* head)
{
	Node* cur = head;
	Node* next_next;

	if (cur == nullptr)
	{
		cout << "no entries \n " << endl;
		return;
	}

	while(cur->next != nullptr)
	{
		if (cur->data == cur->next->data)
		{
			next_next = cur->next->next;
			free(cur->next);
			cur->next = next_next;
		} else
		{
			cur = cur->next;
		}
	}
}
// remove duplicates in unsorted list
void removeDups(Node* head)
{
	Node* ptr1, *ptr2, *dup;
	ptr1 = head;

	while (ptr1 != nullptr) 
	{
		ptr2 = ptr1;
		while (ptr2->next != nullptr)
		{
			if (ptr1->data == ptr2->next->data)
			{
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete dup;
			} else {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}

void reverse(Node** head)
{
	Node *cur = *head;
	Node *next;
	Node *prev = nullptr;

	while(cur != nullptr)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*head = prev;
}

void reserveListusingStack(Node** head)
{
	stack<Node*> s;
	Node* temp = *head;

	while(temp->next != nullptr)
	{
		s.push(temp);
		temp = temp->next;
	}

	*head = temp;

	while (!s.empty())
	{
		temp->next = s.top();
		s.pop();
		temp = temp->next;
	}
	temp->next = nullptr;
}

// inplace with dummy
// delete duplicates ,
Node* mergesortedlist(Node* list1, Node* list2)
{
	Node last;
	last.next = nullptr;
	Node* temp = &last;

	while (list1 && list2)
	{
		if (list1->data < list2->data)
		{
			temp->next = list1;
			list1 = list1->next;
		} else if (list2->data < list1->data)
		{
			temp->next = list2;
			list2 = list2->next;
		} else 
		{
			temp->next = list1;
			list1 = list1->next;
			list2 = list2->next;
		}
		temp = temp->next;
	}
	if (list1 != nullptr)
	{
		temp->next = list1;
	}

	if (list2 != nullptr)
	{
		temp->next = list2;
	}

	return last.next;
}	
// create new list , remove duplicates
// return the list
Node* mergesortedlistNew(Node* list1, Node* list2)
{
	Node last;
	last.next = nullptr;
	Node* temp = &last;

	while (list1 && list2)
	{
		if (list1->data < list2->data)
		{
			temp->next = new Node(list1->data);
			list1 = list1->next;
		} else if (list2->data < list1->data)
		{
			temp->next = new Node(list2->data);
			list2 = list2->next;
		} else 
		{
			temp->next = new Node(list1->data);
			list1 = list1->next;
			list2 = list2->next;
		}
		temp = temp->next;
	}
	while (list1 != nullptr)
	{
		temp->next = new Node(list1->data);
		list1 = list1->next;
	}

	while (list2 != nullptr)
	{
		temp->next = new Node(list2->data);
		list2 = list2->next;

	}

	return last.next;
}	
int main()
{
	Node* head = nullptr;
	for (int i = 0; i < 10; i++) {
		//appendAtFront(&head, i);
		appendAtLast(&head, i);
//		appendAtLast(&head, i);
	}
#if 0
	printlist(head);
	deleteAtFront(&head);
	printlist(head);
	deleteAtPos(&head, 1);
	deleteList(&head);
	printlist(head);
	insertAtPos(head, 99, 3);
	printlist(head);
	nthnodefromend(head, 3);
	deleteAtPos(&head, 1);
	printlist(head);
	listmiddle(head);
#endif
//	printlist(head);
//	removeDuplicatesSortedList(head);
//	removeDups(head);
//	reverse(&head);
//	reserveListusingStack(&head);
	Node* head1 = nullptr;
	appendAtLast(&head1, 5);
	appendAtLast(&head1, 15);
	appendAtLast(&head1, 25);
	appendAtLast(&head1, 35);
	appendAtLast(&head1, 45);
	printlist(head1);

	Node* head2 = nullptr;
	appendAtLast(&head2, 2);
	appendAtLast(&head2, 16);
	appendAtLast(&head2, 24);
	appendAtLast(&head2, 36);
	appendAtLast(&head2, 43);
	printlist(head2);

	Node* list = mergesortedlistNew(head1, head2); 
	printlist(list);

	return 0;
}

