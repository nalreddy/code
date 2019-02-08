protected virtual destructor

=========
#include<iostream>

using namespace std;

class A
{
    protected:

        ~A() { cout << "A destructor " << endl; }

};

class B: public A
{
    public:
        ~B() { cout << " B destructor " << endl; }
};

int main()
{
    A *a;
    {
        a = new B();
        delete a;
    }

    return 0;
}


