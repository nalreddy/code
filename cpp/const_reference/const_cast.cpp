#include<iostream>

using namespace std;

class sig
{
    public:
        sig(int x) { s = x; }
        void print() { cout <<  " sig = " << s << endl; } 
        void set(int x) { s = x; }
    private:
        int s;
};

class A
{
    public :
        sig& get() const 
        {
            return *sg;
        }
        A(int _x) {  sg = new sig(_x); }

        void print() { sg->print(); }

        friend class B;
    private :
        sig *sg;
};

class B
{
    public :
        B(A &a) { sig &c = a.get();  c.set(20); }
};


int main()
{
    A a(10);
    B b(a);

    a.print();
    return 0;
}
