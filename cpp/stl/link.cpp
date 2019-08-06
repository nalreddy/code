#include<iostream>
#include<list>
#include <iterator>

using namespace std;

class A
{
    public:
        A() { cout << "ctor " << endl; }
        ~A() { cout << "dtor " << endl; }
};

int main()
{
    {
        list<A> l;
        list<A> :: iterator it = l.begin();

        A a1;
        l.push_back(a1);
#if 0
        l.push_back(1);
        l.push_back(10);
        l.push_back(11);

        while(l.end() != it) {
            cout << *it++;
#endif
    }

    return 0;
}
