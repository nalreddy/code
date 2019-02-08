#include<iostream>
#if 0
#include<iostream> 
using namespace std; 
  
class Derived; 
  
class Base { 
    private: 
            virtual void fun() { cout << "Base Fun"; } 
            friend int main(); 
}; 
  
class Derived: public Base { 
    public: 
            void fun() { cout << "Derived Fun"; } 
}; 
  
int main() 
{ 
       Base *ptr = new Derived; 
          ptr->fun(); 
             return 0; 
} 
#endif
using namespace std;


class A
{
    protected:
          virtual void f1() { cout << "A" << __func__ << endl; }
};

class B : public A
{
    protected:
          void f1() { A::f1();  cout << "B"<< __func__ <<  endl; }
//          void f2() { cout << "B"<< __func__ <<  endl; }
};


int main()
{
    A *a;

    a = new B();

    a->f1();
  //  a->f2();

    return 0;
}
