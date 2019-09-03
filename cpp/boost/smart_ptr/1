#include<iostream>
#include<memory>

using namespace std;

class A
{
    public:
        A() { cout << " ctor " << endl; }
        ~A() { cout << " dtor " << endl; }
        void print() { cout << " print A " << endl; }
};

void func(std::unique_ptr<A> ptr)
{
    ptr->print();
}

int main()
{
    std::unique_ptr<A> a = std::make_unique<A>();
//    std::unique_ptr<A> b = move(a);

    func(std::move(a));
    if(a)
        cout << "not null"<< endl;
    else
        cout << " null " << endl;
 //   a->print();

    return 0;
}
