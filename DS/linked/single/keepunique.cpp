#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	Node(int data)
	{
	this->data = data;
	}
};

void deleteduplicate(Node** head)
{
	Node* cur = *head;
	Node dummy;
	dummy.next = nullptr;
	Node* temp = &dummy;
	while(cur != nullptr)
	{
		if (cur->data == cur->next)
		{
		   prev =  
		  
		
		}
	}
}

void print(Node* list)
{
	while (list != nullptr)
	{
		cout << list->next << " " << endl;
		list = list->next;
	}
}
int main()
{
	Node* head = nullptr;
	head = new Node(20);
	head->next = new Node(20);;
	head->next->next = new Node(23);
	head->next->next->next = new Node(24);
	head->next->next->next->next = new Node(24);
	head->next->next->next->next->next = new Node(25);

	return 0;
}
