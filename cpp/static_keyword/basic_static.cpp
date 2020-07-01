#include<iostream>

using namespace std;

struct B
{
};

class A
{
    public:
        A(bar b)
        {
            cout << "A ctor \n";
        }
        ~A()
        {
            cout << " A dtor called \n";
        }

        //static cann't be const, virtual,volatile
        static void show()
        {
            cout << " static \n";
        }

        typedef B bar;
    private: 
        B b;
};

int main()
{
    struct B b;
    A a(b);

    A::show();

    return 0;
}
