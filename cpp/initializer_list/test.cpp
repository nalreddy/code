#include<iostream>

using namespace std;

class A
{
    public:
        A() { x = 0; }
        A(int x): x(x) { } 
    private: 
        int x;
};

class B : public A
{
    public:
        B(int _a, int _b, int _x) : a(_a), A(_x), b(_b)
        {
        }

        void print()
        {
            cout << " a = " << a << " b = " << b << endl;

        }

    private:
        int a;
        int b;
};

int main()
{
    B b(1,2,3);

    b.print();

    return 0;
}
