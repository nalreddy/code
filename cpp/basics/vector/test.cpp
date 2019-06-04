#include<iostream>
#include "vector.hpp"
#include<stdexcept>

using namespace std;
using namespace ds;

void f(Container& c)
{
    try {
        c[10] = 9;
    }
    catch (const std::out_of_range& e ) {
        cout <<" index  out of range in f " << endl;
    }
}

void print(Vector&& v)
{
    cout << " size  " << v.size() << endl;
}

int main()
{
    Vector v(8);
    //Vector v1 = v;
//  Vector v1(v);
//    Vector v1(5);

  //  v1 = v;


//    f(v);
    print(v);
cout << " test size " << v.size();
    return 0;
}
