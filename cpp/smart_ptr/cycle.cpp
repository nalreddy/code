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
#if 0
void print(boost::weak_ptr<A> &w)
{
    boost::shared_ptr<A> sh = w.lock();
    if (sh)
        std::cout << "valid " << '\n';
    else 
        std::cout << "invalid " << '\n';
}
#endif

class B
{
    public:
        B(boost::shared_ptr<A> a):mAW(a)
        {
            cout << " B ctor " << endl;
        }

        ~B()
        {
            cout << "B dtor " << endl;
        }
    private:
        boost::weak_ptr<A> mAW;
};

int main()
{
    boost::shared_ptr<A> a{new A()};
    {
        boost::shared_ptr<B> b{new B(a)};
    }
//    print(std::ref(a));

    return 0;
}
