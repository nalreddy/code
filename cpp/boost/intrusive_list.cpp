#include<iostream>

using namespace std;


void print(int &x)
{
    int *ptr = &x;
    cout << "val " << x;
    cout << "ptr " << *ptr;
}

int main()
{
    int y = 3;
    print(y);
    return 0;
}
