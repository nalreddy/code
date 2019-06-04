#include<iostream>

using namespace std;

class A
{
    public:
        A(int x) : x(x) { }

        A& operator ++()
        {
            x += 1;
            cout << " no param " << endl;
        }

        A& operator ++(int) 
        {
            x += 1;
            cout << " with param " << endl;
        }

        void print()
        {
            cout << " x = " << x << endl;
        }
    private:
        int x;
};

int main()
{
    A a(1);

    ++a;
    a++;
    a.print();
    

    return 0;
}
