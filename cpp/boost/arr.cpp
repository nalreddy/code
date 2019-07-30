#include<iostream>
#include<boost/scoped_array.hpp>

using boost::scoped_array;

class A
{
    public:
        A() { std::cout << " ctor called " << std::endl;}
        A(int x)
        {
        }
};

int main()
{
    boost::scoped_array<A> ar(new A[10]);

    return 0;
}
