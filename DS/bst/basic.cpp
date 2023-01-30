#include<iostream>
#include<stack>

using namespace std;

struct Node 
{
	int val;
	struct Node* right;
	struct Node* left;
	Node(int data)
	{
		val = data;
		right = nullptr;
		left = nullptr;
	}

};

void inorderT(struct Node* root)
{
	if (root != nullptr)
	{
		inorderT(root->left);
		cout << root->val << " ";
		inorderT(root->right);
	}
	return;
}

struct Node* insert(struct Node* root, int key)
{
	if (root == nullptr)
		return new Node(key);

	if (key < root->val)
	{
		root->left = insert(root->left, key);
	} else if ( key > root->val)
	{
		root->right = insert(root->right, key);
	}
	return root;
}

int height(struct Node *root)
{
	int l, r;
	if (root == nullptr) return 0;

	l = height(root->left);
	r = height(root->right);

	if (l >= r) return l+1;
	else 
		return r+1;
}

void inorderI(struct Node* root)
{
	stack<Node*> st;
	struct Node* temp = root;

	while(temp != nullptr || !st.empty())
	{
		if (temp != nullptr)
		{
		 st.push(temp);
		 temp = temp->left;
		} else 
		{
		 temp = st.top();
		 st.pop();
		 cout << temp->val << " ";
		 temp = temp->right;
		}
	}
	cout << endl;
}

struct Node* minval(struct Node* root)
{
	struct Node* cur = root;

	while (cur && cur->left)
	{
		 cur = cur->left;
	}
	return cur;
}

void deleteNode(struct Node* root, int key )
{
	if (!root)
		return nullptr;

	if (key > root->val)
	{
		root->right = deleteNode(root->right, key);
	} else if ( key < root->val)
	{
		root->left = deleteNode(root->left, key);
	} else {

		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			return nullptr;
		}

		if (root->left == nullptr)
		{
			struct Node* temp = root->right;
			delete root;
			return temp;
		}
		if ( root->right == nullptr)
		{
			struct Node* temp = root->left;
			delete root;
			return temp;
		}
		struct Node* temp = minvalu(root->right);
		root->val = temp->val;
		root->right = deleteNode(root->right, temp->val);
	}
	return root;
}

int main()
{
	struct Node* root = nullptr;
	root = new Node(50);

#if 0
	root->left = new Node(40);
	root->right = new Node(70);


	root->left->right = new Node(45);
	root->left->left = new Node(30);
	root->right->left = new Node(60);
	root->right->right = new Node(80);
#endif
	insert(root, 40);
	insert(root, 70);
	insert(root, 45);
	insert(root, 30);
	insert(root, 60);
	insert(root, 80);
	inorderI(root);
	cout << endl;
	cout << "height " << height(root) << endl;
	return 0;
}

