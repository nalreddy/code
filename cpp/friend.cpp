#include<iostream>

using namespace std;

class B; 

class A
{
    private :
        int x;
    public :
        int y;
        A() {}
        A(int a, int b)
        {
            x = a;
            y = b;
        }
        void  showB(B &);
        friend class B;
};

class B 
{
    private :
        int b;

    public :
        B()
        {
            b = 2;
        }

        friend void A::showB(B &);
        void print(A &a) 
        {
            cout <<  a.x << endl;
        }
};

void  A::showB(B &v){
            cout << v.b <<endl;
}
   
int main()
{
    A a(2,3);

    B b;

    b.print(a);

    a.showB(b);
    return 0;
}
