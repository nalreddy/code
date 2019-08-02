#include<iostream>
#include<stack>

using namespace std;

struct Node
{
    char ch;
    struct Node* left, *right;
};

struct Node* getNode(char ch)
{
    struct Node* temp = new Node;
    temp->ch  = ch;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

bool isOperator(char ch)
{
    if (ch ==  '*' || ch == '+' || ch == '-' || ch == '/' || ch == '^')
        return true;
    else false;
}

void traverse(struct Node* ptr)
{

    if(ptr) {
        traverse(ptr->left);
        cout << ptr->ch << " ";
        traverse(ptr->right);
    }
}

struct Node* getExpression(char str[])
{
    cout << "enter " << __func__;
    stack<struct Node*> st;

    int i = 0;
    while(str[i] != '\0')
    {
        if (isOperator(str[i]))
        {
            struct Node* t1 = nullptr;
            struct Node* t2 = nullptr;

            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();

            struct Node* temp = getNode(str[i]);
        // if temp not null
            temp->left = t2;
            temp->right = t1;
            st.push(temp);
        } else {
            st.push(getNode(str[i]));
        }
        i++;
    }

    struct Node* temp = st.top();
    st.pop();
    cout << "Exit " << __func__;
    return temp;
}

int main()
{
    char str[] = "ab+*cd-";

    struct Node* root = getExpression(str);
 //   traverse(root);

    return 0;
}
