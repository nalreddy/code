#include<iostream>
#include<stack>
// Linked list Node

using namespace std;

struct Node {
        int data;
        struct Node* next;
        struct Node* bottom;

        Node()
        {
        }

        Node(int x)
        {
                data = x;
                next = NULL;
                bottom = NULL;
        }
};

void print(Node* head)
{
        while (head != nullptr)
        {
                cout <<  head->data << "  ";
                head = head->bottom;
        }
}

void printList(Node* head)
{
        while (head != nullptr)
        {
                cout << "top " << head->data << endl;
                if (head->bottom)
                {
                        Node* temp = head->bottom;
                        while(temp != nullptr)
                        {
                                cout << temp->data << " ";
                                temp = temp->bottom;
                        }
                }
                head = head->next;
                cout << endl;
        }
}

Node* merge(Node* list1, Node* list2)
{
        Node last;
        Node* temp = &last;

        while (list1 && list2)
        {
                if (list1->data <= list2->data)
                {
                        temp->bottom = list1;
                        list1 = list1->bottom;
                } else
                {
                        temp->bottom = list2;
                        list2 = list2->bottom;
                }
                temp = temp->bottom;
        }
        if (list1 != nullptr)
        {
                temp->bottom = list1;
        }

        if (list2 != nullptr)
        {
                temp->bottom = list2;
        }

        return last.bottom;
}

void flatten(Node* head)
{
        stack<Node*> s;
        Node* temp = head;
        Node* root;

        while(temp != nullptr)
        {
                s.push(temp);
                temp = temp->next;
        }

        while(!s.empty())
        {
                root = s.top();
                s.pop();
                root->next = nullptr;
                if (!s.empty()) {
                        Node* second = s.top();
                        second->next = nullptr;
                        s.pop();
                        root = merge(root, second);
                        s.push(root);
                }
#if 0
                if (first->bottom) {
                        merge(first, second);
                } else {
                        first->next = second;
                }
#endif
        }
        print(root);
}
int main(void)
{
        // This code builds the flattened linked list
        // of first picture in this article ;
        Node* head = new Node(5);
        auto temp = head;
        auto bt = head;
        bt->bottom = new Node(7);
        bt->bottom->bottom = new Node(8);
        bt->bottom->bottom->bottom = new Node(30);
        temp->next = new Node(10);

        temp = temp->next;
        bt = temp;
        bt->bottom = new Node(20);
        temp->next = new Node(19);
        temp = temp->next;
        bt = temp;
        bt->bottom = new Node(22);
        bt->bottom->bottom = new Node(50);
        temp->next = new Node(28);
        temp = temp->next;
        bt = temp;
        bt->bottom = new Node(35);
        bt->bottom->bottom = new Node(40);
        bt->bottom->bottom->bottom = new Node(45);

//      printList(head);
        // Function call
        flatten(head);
        cout << endl;
        return 0;
}



