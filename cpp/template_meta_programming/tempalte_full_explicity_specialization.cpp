#include<iostream>
using namespace std;

//template <int T> void f();
//template <> void f<0>() {}
template <int T> void f() { }


void test()
{
      f<1>();
}
