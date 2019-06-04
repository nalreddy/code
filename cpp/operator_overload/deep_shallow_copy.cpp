#include<iostream>

using namespace std;

class A
{
    public:
        A() { } 
        A(int x)
        {
            ptr = new int(x);
        }
        void set(int x) { *ptr = x; }
        void print() { cout << " *ptr  = " << *ptr << endl; }
#if 0
        A& operator = (A t)
        {
            *ptr = *(t.ptr);
        }
#endif
        A& operator = (const A& t)
        {
            *ptr = *(t.ptr);
        }


    private:
        int *ptr;
};

int main()
{
    A a(7);

    A b;
    b = a;

    a.set(8);

    a.print();
    b.print();

    return 0;
}
