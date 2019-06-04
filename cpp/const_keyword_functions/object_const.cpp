#include<iostream>

using namespace std;


class A
{
    public:
        A() {
            x = 1;
            y = 3;
        }
        void print() const
        {
            cout << " x = " << x << endl;
            cout << " y = " << A::y << endl;
        }
        void print()
        {
             x = 3;
            cout << " x = " << x << endl;
        }
    private:

    int x;
    static int y;
};

int main()
{
    A a;

    a.print();

    const A c;

    c.print();
//    c.show();

    return 0;
}

