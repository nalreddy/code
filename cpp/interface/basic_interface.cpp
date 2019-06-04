#include<iostream>

using namespace std;
// diff betweeen interface and abstract class 
//interface class with all pure virtual functions
// abstract class class with some of non pure virtual functions

class A
{
    public:
        virtual void cal() = 0;
        void setx(int _x) { x = _x; }
        void sety(int _y) { y = _y; }

    protected:
        int x;
        int y;
};

class B : public A
{
    public:
        void cal() { cout << " class B product " << (x*y) << endl; }
};

class C : public A
{
    public:
        void cal() { cout << " class C product " << (x*y) << endl; }
};


int main()
{
    A *a = new B();

    a->setx(10);
    a->sety(10);
    a->cal();

    a = new C();

    a->setx(20);
    a->sety(30);
    a->cal();


    return 0;
}
