#include<iostream>

using namespace std;


class A
{
    public:
    virtual void print() = 0;
};
#if 0
class C : public A
{
    public: 
     virtual void show() = 0;
}
#endif

class B : public A
{
    public:
        void print()
        {
            cout << " print B" << endl;
        }

        void show()
        {
            cout << " show " << endl;
        }
};

int main()
{
    A *a = new B();

    a->print();
    a->show();
    return 0;
}
