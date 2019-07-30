#include<iostream>
#include "B.hpp"
#include "A.hpp"

B::B() { ai = new A();};

int main()
{
    B b;
    return 0;
}
