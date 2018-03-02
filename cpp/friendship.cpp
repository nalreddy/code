#include<iostream>
#include "friendship.hpp"
void A::printB(B b) {
    std::cout<< " B data \n"<<b.y;
}

                            
void B::printA(A a) {
     std::cout<< " A data a.a \n"<<a.x;
}

int main()
{
    A a;

    B b;
    b.printA(a); 

    a.printB(b); 
    return 0;
}

