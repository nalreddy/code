#include<iostream>

using namespace std;

class A
{
    public:
        A()
        {
            cout << " A's constructor \n";
        }
        void testA()
        {
            throw 'a';
        }
        ~A()
        {
            cout << " A's destructor \n" << endl;
        }
};

class B : public A
{
    public:
        B()
        {
            cout << " B's constructor \n";
        }
        void testB()
        {
            throw 'b';
        }
        ~B()
        {
            cout << " B's destructor \n" << endl;
        }

};

int main()
{
    B b;
    return 0;
}
