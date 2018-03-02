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

int main()
{
    A *a = new A();

    unique_ptr<A> ptr(a);

    cout<<ptr.get();

    return 1;
}
