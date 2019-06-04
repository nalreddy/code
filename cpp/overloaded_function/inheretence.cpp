#include<iostream>

using namespace std;

class A
{
    public:
        A()
        {
            cout << " A ctor " << endl;
        }

        void* operator new(size_t size)
        {
            cout << "size_t " << size << endl;
        }
};

class B : public A
{
    public:
        B()
        {
            cout << " B ctor " << endl;
        }

        void* operator new(size_t size)
        {
            cout << " size_t B " << size << endl;
        }
};


int main()
{
    B *b = new B();

    return 0;
}
