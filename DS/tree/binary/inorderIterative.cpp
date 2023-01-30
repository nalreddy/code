#include<iostream>
#include<stack>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void inOrder(struct Node* root)
{
	struct Node* cur = root;
	stack<struct Node*> st;

	while (cur != nullptr || st.empty() == false)
	{
		while (cur != nullptr)
		{
			st.push(cur);
			cur = cur->left;
		}
		cur = st.top();
		cout << cur->data;
		st.pop();
		cur = cur->right;
	}
}

int main()
{
 
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
 
    inOrder(root);
    return 0;
} 
