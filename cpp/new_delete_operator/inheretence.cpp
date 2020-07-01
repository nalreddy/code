#include<iostream>

using namespace std;

class A
{
    public:

        A()
        {
            cout << " default A actor " << endl;
        }

        void* operator new(size_t size)
        {
            cout << " normal A new " << endl;
            return ::operator new(size);
        }

        void operator delete(void *ptr)
        {
            cout << " normal A delete " << endl;
        }
#if 0
        virtual ~A()
        {
            cout << " default A dctor " << endl;
        }
#endif
};

class B  : public A
{
    public:

        B()
        {
            cout << " default B actor " << endl;
        }

        void* operator new(size_t size)
        {
            cout << " normal B new " << endl;
            return ::operator new(size);
        }

        void operator delete(void *ptr)
        {
            cout << " normal B delete " << endl;
        }
#if 0
        virtual ~B()
        {
            cout << " default B  dctor " << endl;
        }
#endif
};

int main()
{
#if 0
    {
        A *a = new A();
        delete a;
    }
#else
    cout << " xxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    {
        A *b = new B();
        delete b;
    }
#endif
    return 0;
}
