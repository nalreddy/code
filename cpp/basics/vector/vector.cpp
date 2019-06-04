#include<stdexcept>
#include<iostream>
#include "vector.hpp"

using namespace std;
using namespace ds;

Vector::Vector(int s) : elem(new double[s]), sz(s) { cout << " vector ctor " <<endl; }
Vector::~Vector()
{
    cout << " dtor" << endl;
    delete []elem;
}

Vector :: Vector (const Vector& v)
{
    sz = v.sz;
    elem = new double[sz];
    for(int i = 0; i < sz; i++)
    {
        elem[i] = v.elem[i];
    }
    cout << "copy ctor " << endl;
}

Vector :: Vector (Vector&& v)
{
    sz = v.sz;
    elem = v.elem;
    v.sz = 0;
    v.elem = nullptr;
    cout << "rvalue ctor " << endl;
}

Vector& Vector ::operator =(const Vector& v)
{
    double* p = new double[v.sz];
    for(int i = 0; i < v.sz; i++)
    {
        p[i] = v.elem[i];
    }
    delete []elem;
    sz = v.sz;
    elem = p;
    cout << " operator assingmen" << endl;
    return *this;
}

double& Vector :: operator [](int i)
{
    if ( i < 0 || i > size()) throw std::out_of_range("index out ");
    cout << " i = " << i << endl;
    return elem[i];
}
int Vector :: size() { return sz; }
