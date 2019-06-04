#include<iostream>

using namespace std;
// aligment and struct packing ,padding to word size

struct A
{
    int b:2;
    char a:3;
    char c:1;
};

int main()
{
    cout << sizeof(struct A) << endl;
    return 0;
};
