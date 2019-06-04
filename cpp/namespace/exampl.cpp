#include<iostream>

using namespace std;

namespace A
{
    void print()
    {
        cout << " A::printing\n";
    }
    int x = 2;
}

namespace B
{
    void print()
    {
        cout << " B::printing\n";
    }
    int x = 2;
}


void print()
{
    cout << " global print \n";
}

int main()
{
    A::print();
    print();
    B::print();
    cout << " x = " << A::x << endl;
    return 0;
}
