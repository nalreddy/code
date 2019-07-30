#include<iostream>

using namespace std;

class A
{
    public:
        ~A() {};
        virtual void test() = 0;
};

class B : A
{
}
