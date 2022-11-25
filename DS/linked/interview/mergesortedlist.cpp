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

		ListNode* makeList(ListNode* list) {
			ListNode* tlist;

			if (list == nullptr) {
				return nullptr;
			}

			while(list) {
				push(&tlist, list->val);
				list = list->next;
			}
			return tlist;
		}
#if 0
		// Remove duplicates
		ListNode* mergeInplace(ListNode* list1, ListNode* list2) {
			ListNode tempList;
			ListNode* refPtr = &tempList;

			tempList.next = nullptr;

			if (list1 == nullptr) {
				return list2;
			}
			if (list2 == nullptr) {
				return list1;
			}

			while (list1 != nullptr || list2 != nullptr) {
				if (list1 && list2) {
					if (list1->val < list2->val) {
						refPtr->next = list1;
						list1 = list1->next;
					} else if (list2->val < list1->val) {
						refPtr->next = list2;
						list2 = list2->next;
					} else {
						refPtr->next = list1;
						list1 = list1->next;
						list2 = list2->next;
					}
				} else {
					if (list1 != nullptr) {
						refPtr->next = list1;
						list1 = list1->next;
						break;
					} else {
						refPtr->next = list2;
						list2 = list2->next;
						break;
					}
				}
				refPtr = refPtr->next;
				
			}
			return tempList.next;

		}

		// Remove duplicates
		ListNode* mergeInplace(ListNode* list1, ListNode* list2) {

			if (list1 == nullptr) {
				return list2;
			}
			if (list2 == nullptr) {
				return list1;
			}

			ListNode* ptr = list1;
			if (list1->val > list2->val) {
				ptr = list2;
				list2 = list2->next;
			} else {
				list1 = list1->next;
			}

			ListNode* cur = ptr;

			while (list1 && list2) {
					if (list1->val < list2->val) {
						cur->next = list1;
						list1 = list1->next;
					} else  if (list2->val < list1->val){
						cur->next = list2;
						list2 = list2->next;
					} else {
						cur->next = list2;
						list1 = list1->next;
						list2 = list2->next;
					}
					cur = cur->next;
				
			}
			if (!list1) {
				cur->next = list2;
			} else {
				cur->next = list1;
			}
			return ptr;
		}

#endif

		// DummyNode 
		ListNode* mergeInplace(ListNode* list1, ListNode* list2) {
			ListNode dummyNode;
			ListNode* temp = &dummyNode;
			dummyNode.next =  nullptr;

			while(list1 && list2) {
				temp->next = list1 ? list1 : list2;
				if (list1->val < list2->val) {
					temp->next = list1;
					list1 = list1->next;
				} else if (list2->val < list1->val) {
					temp->next = list2;
					list2 = list2->next;
				} else {
					temp->next = list1;
					list1 = list1->next;
					list2 = list2->next;
				}
				temp = temp->next;
			}

			temp->next = list1 ? list1 : list2;
			return dummyNode.next;
		}

		ListNode* merge(ListNode* list1, ListNode* list2) {
			ListNode* tempList = nullptr;

			if (list1 == nullptr) {
				return makeList(list2);
			}
			if (list2 == nullptr) {
				return makeList(list1);
			}

			while (list1 != nullptr || list2 != nullptr) {
				if (list1 && list2) {
					if (list1->val > list2->val) {
						push(&tempList, list1->val);
						list1 = list1->next;
					} else if (list2->val > list1->val) {
						push(&tempList, list2->val);
						list2 = list2->next;
					} else {
						push(&tempList, list2->val);
						list1 = list1->next;
						list2 = list2->next;
					}
				} else {
					if (list1 != nullptr) {
						push(&tempList, list1->val);
						list1 = list1->next;
					} else {
						push(&tempList, list2->val);
						list2 = list2->next;
					}
				}
			}
			return tempList;
		}
#if 0
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			ListNode dummy(INT_MIN);
			ListNode *tail = &dummy;

			while (l1 && l2) {
				if (l1->val < l2->val) {
					tail->next = l1;
					l1 = l1->next;
				} else {
					tail->next = l2;
					l2 = l2->next;
				}
				tail = tail->next;
			}

			tail->next = l1 ? l1 : l2;
			return dummy.next;
		}
#endif
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
	Solution s;
	ListNode* head1 = nullptr;
	s.push(&head1, 35);
	s.push(&head1, 15);
	s.push(&head1, 13);
	s.push(&head1, 2);
	s.print(head1);

	ListNode* head2 = nullptr;
	s.push(&head2, 36);
	s.push(&head2, 26);
	s.push(&head2, 18);
	s.push(&head2, 13);
	s.push(&head2, 10);
	s.print(head2);
	ListNode* head3 = nullptr;

	head3 = s.mergeInplace(head1, head2);

	s.print(head3);

	return 0;
}
