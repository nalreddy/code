#include <boost/scoped_ptr.hpp>
#include<iostream>

using namespace std;

class A
{
    public:
    A()
    {
        test();
    }
    ~A()
    {
        cout << " dest " << endl;
    }

    private:
    void test()
    {
        cout << " test" << endl;
    }

};


int main()
{
    {
        boost::scoped_ptr<A> a(new A());
    }
    return 0;
}
