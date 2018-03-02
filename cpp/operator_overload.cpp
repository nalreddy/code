#include<iostream>

using namespace std;

class A
{
    private :
        int x;
        char c;
    public :
        A(int a, char b)
        {
            x = a;
            c = b;
        }

        friend ostream & operator << (ostream &os, const A &a);
};

ostream & operator << (ostream &os, const A &a)
        {
            cout << "a = " << a.x << " " << "c = " << a.c << endl;
            return os;
        }


int main()
{
    A a(2 ,'s');

    cout <<a;

    return 0;
}
