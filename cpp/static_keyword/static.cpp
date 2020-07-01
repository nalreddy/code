#include<iostream>

using namespace std;

class A
{
    private:
        static int x;

    public:
        A () 
        {
        }
        static void print()
        {
            cout << "x = "<< x << endl;
        }
        static void set(int _x)
        {
            x = _x;
        }
};

int A::x = 0;

int main()
{
    A::set(10);
    A a;
    A::set(19);
    a.print();
    return 0;
}
