#include<iostream>

using namespace std;

template <typename T>

int comp(T a, T b) 
{
    
    return a == b ? 1 : 0;
}


int main()
{
    comp(1,2);
    comp(1.5,2.6);

    return 0;
}
