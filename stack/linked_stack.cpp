#include<iostream>

using namespace std;

// TODO make it template
struct node
{
    int data;
    struct node *next;
};

class stack
{
    public:
	stack() : stack_size(0), top(NULL) { }
	void push(int data);
	void pop();
	void print();
	unsigned int size();
    private:
	unsigned int stack_size;
	struct node *top;
	struct node* get_node(int data);
};

struct node* stack :: get_node(int data)
{
    struct node* temp = new struct node;

    if( temp == NULL )
    {
	cout << "out of memory " << endl;
	//handle memory issue
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void stack :: push (int data)
{
    struct node* temp = get_node(data);

    if(!temp) { return; }

    if(!top) {
	top = temp;
	stack_size++;
	return;
    }

    temp->next = top;
    top = temp;
    stack_size++;
    return;
}

void stack :: pop()
{
    struct node* temp = top;

    if (!top) {
	cout << "oops nothing to pop" << endl;
	return;
    }

    stack_size--;
    top = top->next ? temp->next : NULL;

    cout << "poped " << temp->data << endl;
    delete temp;
    return;
}

unsigned int stack :: size()
{
    return stack_size;
}

void stack :: print()
{
    struct node* cur = top;

    if(!top) {
	cout << "nothing to print" << endl;
	return;
    }

    while ( cur ) {
	cout << cur->data << endl;
	cur = cur->next;
    }
}

int main()
{
    stack st;

    cout << "size = " << st.size() << endl;
    st.push(10);
    st.push(11);
    st.push(12);
    st.push(13);
    st.print();
    cout << "size = " << st.size() << endl;

    st.pop();
    cout << "size = " << st.size() << endl;
    st.print();
    st.pop();
    st.pop();
    st.pop();
    cout << "size = " << st.size() << endl;
    st.print();
    return 0;
}
