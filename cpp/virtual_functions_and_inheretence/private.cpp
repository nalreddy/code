Using Virtual Keyword and Accessing Private Method of Derived class

#include<iostream>

using namespace std;

class A
{
    public:
        virtual void show()
        {
            cout << "Base class\n";
        }
};

class B: public A
{
    private:
        virtual void show()
        {
            cout << "Derived class\n";
        }
};

int main()
{
    A *a;
    B b;
    a = &b;
    a -> show(); 
}




