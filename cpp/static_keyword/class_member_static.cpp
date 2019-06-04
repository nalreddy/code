#include<iostream>

using namespace std;

class A
{
    public:
        A()
        {
            cout << " A ctor called " << endl;
        }
        ~A()
        {
            cout << "A dtor called " << endl;
        }
};

class B
{
    public:
        B()
        {
            cout << " B ctor called " << endl;
        }
        ~B()
        {
            cout << " B dtor called " << endl;
        }

    private:
        //static A a;
        A a;
};

int main()
{
    B b;
    return 0;
}
