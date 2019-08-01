#include<iostream>

using namespace std;

struct A
{
    double d;
    int x;
    char y;
    uint8_t* var;
};

int main()
{
    A *a = new A();
    uint8_t* temp = new uint8_t[10];
    a->var = reinterpret_cast<uint8_t*> (temp);
    cout << " A " << sizeof(struct A);
    return 0;
}
