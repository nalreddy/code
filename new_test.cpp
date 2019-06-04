#include<iostream>

using namespace std;


class A
{
    public : 
        A(int x) : _x(x) {}
        ~A() {  cout << " dtor  " << endl; }
        void disp() { cout << _x << endl;}
    private:
        int _x;
};

int main()
{
    A a = A(10);

    a.disp();
    a = A(12);

    a.disp();

    return 0;
}
