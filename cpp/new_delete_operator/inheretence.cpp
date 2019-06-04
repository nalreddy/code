#include<iostream>

using namespace std;

class A
{
    public:

        A()
        {
            cout << " default A actor " << endl;
        }

        static void* operator new(size_t size)
        {
            cout << " normal A new " << endl;
            return ::operator new(size);
        }

        static void operator delete(void *ptr)
        {
            cout << " normal A delete " << endl;
        }

        virtual ~A()
        {
            cout << " default A dctor " << endl;
        }
};

class B  : public A
{
    public:

        B()
        {
            cout << " default B actor " << endl;
        }

        static void* operator new(size_t size)
        {
            cout << " normal B new " << endl;
            return ::operator new(size);
        }

        static void operator delete(void *ptr)
        {
            cout << " normal B delete " << endl;
        }

        ~B()
        {
            cout << " default B  dctor " << endl;
        }
};

int main()
{
    {
        A *a = new A();
        delete a;
    }
    cout << " xxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    {
        A *b = new B();
        delete b;
    }


    return 0;
}
