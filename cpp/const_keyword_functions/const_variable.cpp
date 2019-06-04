#include<iostream>
#include<boost/config.hpp>

using namespace std;

class A
{
   static int x;

    public :
    void print();
    void show(const int& x)
    {
        cout << x;
    }
};
int A::x = 10;

void A:: print()
    {
        cout << " x = " << x; 

        show(x);
    }

int main()
{
    A a;
    a.print();
    return 0;
}
