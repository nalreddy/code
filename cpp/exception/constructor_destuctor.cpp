#include<iostream>

using namespace std;


class A
{
    public:
        A()
        {
            throw 'a';
            cout << "ctor " << endl;
        }
        ~A()
        {
            cout << "dtor " << endl;
        }
};

int main()
{
    {
    A a;
    }
    return 0;
}
