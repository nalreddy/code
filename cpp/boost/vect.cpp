#include<iostream>
#include<boost/container/vector.hpp>

using namespace std;

class A
{

    public:
        A() { cout << " default ctor " << endl; }
        A(int x) { cout << " parameter ctor " << endl; }
};

int main()
{
    boost::container::static_vector<A(1), 10> v;
    return 0;
}
