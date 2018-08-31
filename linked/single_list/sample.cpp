#include<iostream>

using namespace std;

class A
{
    public:
        A() { cout << " Ctor called " << endl; }
        A(int x1) { x = x1; }
        void add(const A &a);
        void test() 
        {
            x += 1;
        }
        ~A() {}
    private:
        int x;
};

void A :: add(const A &a)
{
}

int main()
{
    A a1(1);
    a1.test();
}
