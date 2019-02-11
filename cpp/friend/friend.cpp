#include<iostream>
class B;

class A {

    private:
        int x;

    public:
        A() { x = 1; }

        friend class B;
        void printB(B b);
};


class B
{
    private:
        int y;

    public:
        b() { y = 2; }

        void printA(A a);
};

