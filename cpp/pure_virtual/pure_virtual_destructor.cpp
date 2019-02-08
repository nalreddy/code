#include<iostream>

using namespace std;

class A
{
    public:
        virtual ~A() = 0;
};

A::~A()
{
    cout << " A destructor \n";
}
class B : public A
{
    public:
        void show()
        {
            cout << " B show \n";
        }
};

int main()
{
    B b;
    A a;
    return 0;
}
