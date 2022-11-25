#include<iostream>
using namespace std;

// Definition for singly-linked list.
  struct ListNode {
      int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
	private:
		int nodeCount(ListNode* head) {
			ListNode* cur = head;
			int count = 0;
			while(cur) {
				count++;
				cur = cur->next;
			}
			return count;
		}
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode* cur = head; 
			int pos = nodeCount(head) - n;  // already at head
			ListNode* prev;
			while(pos) {
				prev = cur;
				cur = cur->next;
				pos--;
			}

			if (cur == head) {
				head = head->next;
				delete cur;
				return head;
			}
			prev->next = cur->next;
			cur->next = nullptr;
			delete cur;
			return head;
		}

		ListNode* secondMethod(ListNode** head, int n) {
			ListNode* refptr = *head;
			ListNode* mainptr = *head;

			if (*head == nullptr ) {
				return nullptr;
			}
			while (n--) {
				cout << " n " << n << " " << refptr->val;
				refptr = refptr->next;
				if (refptr == nullptr) {
					cout << "invalid len" << endl;
					return nullptr;
				}

			}
			cout << endl;
			ListNode* prev;
			while(refptr) {
				cout << "loop" << endl;
				prev = mainptr;
				mainptr = mainptr->next;
				refptr = refptr->next;
			}
			if (mainptr == *head) {
				cout << " edge condition  " << endl;
				(*head) = (*head)->next;
				print(*head);
				delete mainptr;
				return *head;
			}
			prev->next = mainptr->next;
			mainptr->next = nullptr;
			delete mainptr;
			return *head;

		}

		void push(ListNode** head_ref, int new_data)
		{
			/* Allocate node */
			ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));

			/* Put in the data */
			new_node->val = new_data;

			/* link the old list off the new node */
			new_node->next = (*head_ref);

			/* move the head to point to the new node */
			(*head_ref) = new_node;
		}

		void print(struct ListNode* head) {
			ListNode* cur = head;

			if (head == nullptr) {
				return;
			}
			while(cur) {
				cout << cur->val << "  ";
				cur = cur->next;
			}
			cout<<endl;
		}
};

int main() {
	ListNode* head = nullptr;
	Solution s;

	s.push(&head, 20);
	s.push(&head, 4);
	s.push(&head, 15);
	s.push(&head, 35);
	s.print(head);
	//s.removeNthFromEnd(head,2);
	s.secondMethod(&head,6);
	s.print(head);


	return 0;
}
