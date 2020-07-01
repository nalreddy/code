#include <boost/shared_ptr.hpp>
 #include <boost/make_shared.hpp>
#include <iostream>

using namespace std;

class B
{
    public:
        B()
        {
            std::cout << "B Ctor" << std::endl;
        }
        ~B()
        {
            std::cout << "B Dotr" << std::endl;
        }
};


class A
{
    public:
        A():
            p1()
        {
            p1 = boost::make_shared<B>();
            std::cout << "Ctor" << std::endl;
        }
        ~A()
        {
            std::cout << "Dotr" << std::endl;
        }
    private:
        boost::shared_ptr<B> p1;
};

int main()
{
    A  a;

//    boost::shared_ptr<A> p1;
  //  p1 = boost::make_shared<A>();
    return 0;
}
