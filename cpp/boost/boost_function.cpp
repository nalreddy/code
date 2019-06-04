#include<iostream>
#include <boost/function.hpp>

using namespace std;

typedef boost::function<bool(int x)> f;

struct A
{
   explicit A(int x) : x(x) { }
    bool operator()(int y) const 
    {
        cout << " y = " << y;
        return x == y;
    }
    int x;
};

void print(int x1 , const f& a)
{
    cout << " print \n" ;
 cout <<a(x1);
}

#if 0
template<typename T>
void print(int x ,const T& fn)
{
    cout << " print " ;
    fn(x);
}
#endif

int main()
{
    print(4, A(4));

    return 0;
}
