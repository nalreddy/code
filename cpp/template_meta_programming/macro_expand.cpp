#include<iostream>

enum Type
{
    one,
    two,
    three
};

template<class T>
struct Trait
{
   const int x = T;
};

int main()
{
    Trait<0> t;
    return 0;
};
