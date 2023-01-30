#include<iostream>
struct Node
{
    int data;
    struct Node* next;
};


Node* deletekth(Node* list, int k)
{
	Node* ptr = list;
	Node* prev = nullptr;
	int count = 2;
	if (k == 1) 
	{
		//delete the list;
	}
	while (ptr != nullptr)
	{
		count++;
		if (count == k)
		{
		  prev->next = ptr->next;
		  delete ptr;
		  count = 0;
		}
		if (count != 0)
		{
			prev = ptr;
		}
		ptr = ptr->next;
	}
}
