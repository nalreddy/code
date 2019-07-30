#include<iostream>

using namespace std;

class A
{
    public:
        virtual void func(bool x =false) = 0;
};

class B : public A
{
    public:
        B() { cout << "ctor : " << endl; }
        void func(bool x  = false) 
        {
            cout << " func  " << endl;
        }
};

int main()
{
    A *b = new B();
    b->func();
    return 0;
}
