#include<iostream>

using namespace std;

int main()
{
    int x = 2;
    int* p = &x;

    cout << " p " << p << "*p " << *p << endl;

    ++*p;//++;
    cout << " p " << p << "*p " << *p << endl;

    return 0;
}
