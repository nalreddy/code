
/* CPP program to check if
a tree is height-balanced or not */

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child and
a pointer to right child */
class Node {
public:
		int data;
		int height;
		Node* left;
		Node* right;
		Node(int d)
		{
				int data = d;
				left = right = NULL;
				height = 0;
		}
};

// Returns true if binary tree
// with root as root is height-balanced
bool isBalanced(Node* root)
{
		stack<Node*> st;
		Node* cur = root;
		while (!cur || !st.empty())
		{
				while(cur != nullptr)
				{
						if (cur->right)
								st.push(cur->right);
						st.push(cur);
						cur = cur->left;
				}	
				cur = st.top();
				st.pop();
				if (cur->right && cur->right == st.top())
				{
						st.pop();
						st.push(cur);
						cur = cur->right;
				} else {
						int left = cur->left ? cur->left->height : 0;
						int right = cur->right ? cur->right->height : 0;

						if (abs(left - right) > 1) return false; 
						cout << cur->data;
						cur->height = max(left, right ) + 1; 
						cur = nullptr;
				}
		}
		return true;
}

// Driver code
int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
//	root->right = new Node(3);
	root->left->left = new Node(4);
//	root->left->right = new Node(5);
	root->left->left->left = new Node(8);

	if (isBalanced(root))
		cout << "Tree is balanced";
	else
		cout << "Tree is not balanced";
	return 0;
}

// This code is contributed by rathbhupendra

