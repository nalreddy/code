#include<iostream>

using namespace std;

class A
{

    public:
        struct Header
        {
            int x ;
        };
        static int x;
        static int d;
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
            d = x - sizeof(Header);
        }

        int get()
        {
            return d;
        }
};


class B : public A
{
    public:
        B()
    {
    }

    static void setB(int y)
    {
        z = y;
        d = z - sizeof(Header);
    }

   static int z;
};

int A::x = 0;
int A::d = 0;
int B::z= 0;

int main()
{
    A::set(16);
    B::set(18);

    
    B b;
    cout << " from A " << b.get() <<endl;
    A a;
    cout << " from A " << a.get() <<endl;
    return 0;
}
