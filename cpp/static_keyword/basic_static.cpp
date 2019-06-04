#include<iostream>

using namespace std;

class A
{
    public:
        A()
        {
            cout << "A ctor \n";
        }
        ~A()
        {
            cout << " A dtor called \n";
        }

        //static cann't be const, virtual,volatile
        static void show() const
        {
            cout << " static \n";
        }
};

int main()
{
    A a;

    A::show();

    return 0;
}
