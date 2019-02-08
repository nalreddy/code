#include<iostream>
#include<memory>

using namespace std;

class A 
{
    public:
        void show()
        {
            cout<<"show A\n";
        }
};

void print() 
{
    A *a = new A();
    shared_ptr<A> ptr(a);

    cout<<ptr.get() << "use count "<<ptr.use_count()<< endl;

    shared_ptr<A> ptr1(a);
#if 0
    cout<<ptr1.get() << "use count "<<ptr1.use_count()<< endl;
    ptr.reset();

    cout<<ptr.get() << "use count "<<ptr.use_count()<< endl;
    cout<<ptr1.get() << "use count "<<ptr1.use_count()<< endl;
#endif

}

int main()
{
    print();

    return 1;
}

