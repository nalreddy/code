#include<iostream>
#include "exampl.hpp"

using namespace std;

int main()
{
    A::print();
    print();
    B::print();
    cout << " x = " << A::x << endl;
    return 0;
}
