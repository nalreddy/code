#include <boost/scoped_ptr.hpp>

#include<iostream>

class A
{
    public:
	    virtual ~A() {}

  virtual   void f() = 0;
};

class B : public A
{
    public:
        B() {
        }
        ~B() {}
        void f() { };
    private :
};


int main()
{
	// A is interface B is class 
#if 0
	boost::scoped_ptr <A> a(new B());  // add namepsace if required lile <svtfs::A>
	
#else
	boost::scoped_ptr <A> a();
	a.reset(new B());
#endif

    return 0;
}
