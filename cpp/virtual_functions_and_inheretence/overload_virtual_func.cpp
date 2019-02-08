#include <iostream>
using namespace std;

class Base
{
    public:
        virtual void fun ( int x = 0)
        {
            cout << "Base::fun(), x = " << x << endl;
        }
        void f1() { cout <<__func__ << endl; }
};

class Derived : public Base
{
    public:
        virtual void fun ( float x = 10.0 )
        {
            cout << "Derived::fun(), x = " << x << endl;
        }
};


int main()
{
    Derived d1;
    Base *bp = &d1;
    bp->fun();
    bp->f1();
    d1.fun();
    d1.fun(1.2);
    return 0;
}
