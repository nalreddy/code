#include<iostream>

class A
{
    public:

  virtual   void f() = 0;
};

class B : public A
{
    public:
        B() {
            a = new B();
        }
        ~B() {}
        void f() { };
    private :
        A *a;
};


int main()
{
    return 0;
}
