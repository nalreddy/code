#include<iostream>

using namespace std;

class A
{
    public:
        A()
        {
            cout << " default Ctor \n";
        }

        explicit A(int x)
        {
            cout << " single Ctor x = " << x << endl;
        }

#if 0
        A(char c)
        {
            cout << " single Ctor char c= " << c << endl;
        }
        explicit A(int x)
        {
            cout << " single Ctor x = " << x << endl;
        }

        explicit A(char c)
        {
            cout << " single Ctor char c= " << c << endl;
        }
#endif
};

int main()
{

    A a1(1);

    A a2 = 1;

    A a3 = 'x';

    return 0;
}
