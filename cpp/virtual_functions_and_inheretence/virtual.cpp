#include<iostream>
//https://www.geeksforgeeks.org/virtual-function-cpp/
//Rules of virtual functions
using namespace std;


class A
{
    public:
          virtual void f1() { cout << "A" << __func__ << endl; }
};

class B : public A
{
    public :
          void f1(int x) { cout << "B"<< __func__ <<  endl; }
//          void f2() { cout << "B"<< __func__ <<  endl; }
};


int main()
{
    A *a;

    a = new B();

    a->f1();
  //  a->f2();

    return 0;
}
