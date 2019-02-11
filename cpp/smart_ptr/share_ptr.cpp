#include<iostream>
#include<memory>

using namespace std;

#if 0
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
#endif


class Foo
{
    public:
        void doSomething()
        {
            cout << " Foo " << __func__ << endl;
        }
        ~Foo()
        {
            cout << " Foo dtor called \n";
        }
};

class Bar
{
    private:
        std::shared_ptr<Foo> pFoo;
    public:
        Bar()
        {
            pFoo = std::shared_ptr<Foo>(new Foo());
        }

        ~Bar()
        {
            cout << " Bar dtor calledd \n";
        }

        std::shared_ptr<Foo> getFoo()
        {
            return pFoo;
        }
};

int main()
{
    std::shared_ptr<Foo> fooptr; 
    {
        Bar br;
        fooptr = br.getFoo();

    }
    fooptr->doSomething();
    return 1;
}

