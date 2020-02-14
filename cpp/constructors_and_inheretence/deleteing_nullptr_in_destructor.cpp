#include<iostream>

using namespace std;

class A
{
    public:
        A()
        {
            p = new int;
        }

        ~A()
        {
            delete p;
        }

    private:
        int *p;
};

int main()
{
    A a;

    return 0;
}
