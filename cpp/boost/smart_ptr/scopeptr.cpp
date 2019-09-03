#include <boost/scoped_ptr.hpp>
#include <iostream>

struct Shoe { ~Shoe() { std::cout << "Buckle my shoe\n"; } };

class MyClass {
    boost::scoped_ptr<Shoe> ptr;
//    Shoe* ptr;
    public:
    ~MyClass() { std::cout << " Myclass dtor " << std::endl; }
    MyClass() : ptr(new Shoe()) { }
};

int main()
{
    {
    MyClass my_instance;
    }
}
