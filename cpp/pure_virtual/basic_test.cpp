#include<iostream>

using namespace std;

class A
{
    public:
        virtual void show() = 0;
        void print()
        {
            cout << " A print \n";
        }
};

class B : public A
{
    public:


        void show()
        {
            cout << "B show \n";
        }
};
int main()
{
    B b;

    b.print();
    return 0;
}
