#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <thread>
#include <functional>
#include <iostream>


using namespace std;

class A
{
    public:
        A()
        {
            cout << " A ctor " << endl;
        }

        ~A()
        {
            cout << "A dtor " << endl;
        }
};

void reset(boost::shared_ptr<A> &sh)
{
    sh.reset();
}

void print(boost::weak_ptr<A> &w)
{
    boost::shared_ptr<A> sh = w.lock();
    if (sh)
        std::cout << "valid " << '\n';
    else 
        std::cout << "invalid " << '\n';
}

int main()
{
    boost::weak_ptr<A> w;
    {
    boost::shared_ptr<A> sh{new A()};
    w = sh;
    }
    print(std::ref(w));

    return 0;
}
