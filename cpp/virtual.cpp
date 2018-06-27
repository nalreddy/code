#include<iostream>

using namespace std;


class A
{
    public:
          virtual void f1() { cout << "A" << endl; }
};

class B : public A
{
    public :
          virtual void f1() { cout << "xBi"<< endl; }
};


int main()
{
    A *a;
    B b;
    a = (A*)&b;

    a->f1();
    A a1;
        a1.f1();
    return 0;
}
