#include<iostream>
#include<boost/array.hpp>


using namespace std;

int main()
{
    boost::array<int, 2>  test;

    if (test[0].valid()) std::cout << "valid " << endl;

    return 0;
}
