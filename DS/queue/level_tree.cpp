#include<iostream>
#include<queue>

using namespace std;

struct TNode
{
   struct TNode *left;
   struct TNode *right;
   int data;
};

struct TNode * getnode(int x){
 struct TNode *temp = new struct TNode;
 temp->left = NULL;
 temp->right = NULL;
 temp->data = x;
 return temp;
}


void in(struct TNode *root)
{
    if(!root)
        return;
    in(root->left);
    cout<< root->data << endl;
    in(root->right);
}

void level_order(struct TNode *root)
{
    struct TNode* cur = root;
    struct TNode* temp = NULL;
    queue<struct TNode *> q;

    if(root == NULL) return;

    q.push(root);

    while(1) {
        temp = q.front();
        q.pop();

        if(temp == NULL) break;

        cout << temp->data << endl;

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
}

int main()
{
   struct TNode *temp = getnode(10);

   temp->left =  getnode(11);
   temp->right =  getnode(12);
   temp->left->left =  getnode(13);
   temp->left->left->right =  getnode(15);
   temp->right->left =  getnode(14);

//   in(temp);

   level_order(temp);
    return 0;
}
