#include<iostream>

using namespace std;

class A
{
    private:
        int x;

    public:
        A () 
        {
            x = 10;
        }
        static int i;
        static void print()
        {
            cout << "i = "<< i << x endl;
        }
};

int A::i = 3;


int main()
{
    A a;

    a.print();
    return 0;
}
