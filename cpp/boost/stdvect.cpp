#include<iostream>
#include<vector>

using namespace std;

class A
{

    public:
        A() { cout << " default ctor " << endl; }
        A(int x) { cout << " parameter ctor " << endl; }
};

int main()
{
    std::vector<A> v;

    size_t max = 36 * 1024;

    for( size_t i = 0 ; i <  max ; i++)
        v.emplace_back(i);


    return 0;
}
