#include<iostream>


template <class T>
class A {
    public :
        T a;
};

int main()
{
    A<int> a;
    A<char> b;
    return 0;
}
