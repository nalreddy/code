#include<iostream>

using namespace std;

namespace A
{
    namespace C
    {
        void print()
        {
            cout << " C::printing\n";
        }
        int x = 2;
    }
    void print()
    {
        cout << " A::printing\n";
    }
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


