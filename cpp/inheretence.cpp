#include<iostream>
using namespace std;

class A
{
    private:
        int x;

        void print_private() 
        {
            cout << "print_private a, x" << a << x << endl;
        }

    protected :
        int p;

        void print_protect()
        {
            cout << " print_protected " << a << x << p << endl;
        }
    public:
        int a;

        A() {

            cout << "As default constructor " << endl;
        }
        A(int x, int a) :x(x), a(a)
        {
        }
        void print_a() 
        { 
            cout <<"print_public a , x  "<< a << x << "" << endl;
            print_private();
        }

};


class B : public A
{

    public :
        B() {
            cout << "Bs default constructor " << endl;
        }

        void print_b()
        {
            print_protect();
            cout << " As members " << a << "" <<  p << endl;
        }
};

class C : public B
{
    public :
        C() {
            cout << "C default constructor " << endl;
        }

        void print_c()
        {
            print_protect();
        }
};

int main()
{
    C c;

    c.print_c();

    return 0;
}
