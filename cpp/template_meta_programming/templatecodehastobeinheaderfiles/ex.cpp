#include<iostream>
#include "ex.hpp"

template<>
void A<int>::print()
{
    std::cout << " x  " ;
}
#if 0
int main()
{
    A<int> a(10);

    a.print();

    return 0;
}
#endif
