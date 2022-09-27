#include<stdio.h>
#include<stdlib.h>
#include"slist.h"

typedef struct node Node;

struct node {
	int data;
	struct node* next;
};

struct list {
	Node* head;
};

List* makeList() {
	List* list;
	list = (List*) malloc(sizeof(List));
	list->head = NULL;
	return list;
}

Node* createNode(int data) {
	Node* node;
	node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
}

// adding at fron for simplicity
void addFirst(int data, List* list) {
	Node* cur = list->head;
	if (cur == NULL) {
		list->head = createNode(data);
	} else {
		list->head = createNode(data);
		list->head->next = cur;
	}
}

// adding at fron for simplicity
void addLast(int data, List* list) {
	Node* cur = list->head;
	if (cur == NULL) {
		list->head = createNode(data);
	} else {
		while(cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = createNode(data);
	}
}

void addAt(int data, int pos, List* list) {
}

void del(int data, List* list) {
	Node* cur = list->head;
	Node* prev = NULL;

	//deleting head
	if (cur->data == data) {
		list->head = cur->next;
		free(cur);
		return;
	}
	while(cur) {
		if (cur->data == data) {
			prev->next = cur->next;
			free(cur);
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}

void reverse(List* list) {
	Node* cur = list->head;
	Node* next;
	Node* prev = NULL;

	while(cur) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	list->head = prev;
}

void delList(List* list) {
	Node* cur;
	Node* next;

	if (list == NULL) {
		printf("empty list\n");
		return;
	}

	cur = list->head;
	while(cur) {
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(list);
}

void display(List* list) {
	Node* cur;
	if (list->head == NULL) {
		printf("empty list\n");
		return;
	}
	cur = list->head;
	while(cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int length(List* list) {
	return 0;
}

void listMid(List* list) {
	Node* slow, *fast;
	slow = fast = list->head;

	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	if (slow) {
		printf("Mid is %d\n", slow->data);
	}
}
