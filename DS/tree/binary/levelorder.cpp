#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};
 
void printLevelOrder(struct Node* root)
{
	if (root == nullptr) return;
	queue<Node*> q;
	q.push(root);

	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		if (temp->left) q.push(temp->left);
		if (temp->right) q.push(temp->right);
	}
}
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}
