#include<iostream>

using namespace std;

int main()
{
    struct A
    {
        int x;
    };

    struct A *a;

    cout << " size of A " << sizeof(A) << endl;
    cout << " size of *a" << sizeof(*a) << endl;
    return 0;
}
