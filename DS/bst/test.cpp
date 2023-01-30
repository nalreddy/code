#include<iostrea>
using namespace std;
 
struct Node {
    int data;
    struct Node *left, *right;
};
 
// helper function to create a new Node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

Node* KthLargestUsingMorrisTraversal(Node* root, int k)
{
	Node* cur = root;
	int count = 0;
	
	while(cur != nullptr)
	{
		if (cur->right == nullptr) {
			count++;
			if (count == k) return cur;
			cur = cur->left;
		} else {

			Node* suc = cur->right;
			while ( suc != nullptr && suc->left != nullptr)
			{
				suc = suc->left;
			}

			if (suc->left == nullptr ) {
				suc->left = cur;
				cur = cur->right;
			} else {
				suc->left = nullptr;
				count++;
				if (count == k) 
				{
					return suc;.
				}
				cur = cur->left;
			}
		}
	}
}

int main()
{
    // Your C++ Code
    /* Constructed binary tree is
          4
        /   \
       2     7
     /  \   /  \
    1    3  6    10 */
 
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(10);
 
    cout << "Finding K-th largest Node in BST : "
         << KthLargestUsingMorrisTraversal(root, 2)->data;
 
    return 0;
}
