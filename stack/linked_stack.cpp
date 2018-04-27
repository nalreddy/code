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
	bool is_empty();
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

    if (is_empty()) {
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

bool stack :: is_empty()
{
    return top == NULL;
}

void stack :: print()
{
    struct node* cur = top;

    if(is_empty()) {
	cout << "nothing to print" << endl;
	return;
    }

    while ( cur ) {
	cout << cur->data << endl;
	cur = cur->next;
    }
}

void stack :: reverse()
{
    struct node* temp = top;

    if (is_empty()) return;

    temp = __reverse(temp);
    temp->next = NULL;
}

#if 0
struct node*  stack :: __reverse(struct node *temp)
{
    struct node* cur = NULL;

    if (temp->next == NULL) { top = temp; return temp; }

     cur = __reverse(temp->next);

     cur->next = temp;
     return temp;
}

void stack :: sort()
{
    struct node* temp = top;

    top = __sort(temp);
}

struct node* stack :: __sort(struct node* temp)
{
    struct node* cur = temp;

    if (cur == NULL) {
	return NULL;
    }
    __sort(temp->next);

    insert(cur,temp);
}
void stack :: insert(struct node* cur, struct node* temp)
{
    if (temp == cur || cur->data < temp->data) {
	cur-
    }
}
#endif

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
#if 0
    st.pop();
    cout << "size = " << st.size() << endl;
    st.print();
    st.pop();
    st.pop();
    st.pop();
    cout << "size = " << st.size() << endl;
    st.print();
#endif
    st.reverse();
    st.print();
    cout << "size = " << st.size() << endl;
    return 0;
}
