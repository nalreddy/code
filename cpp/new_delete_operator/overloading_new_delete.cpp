#include<iostream>

using namespace std;

class A
{
    public:

        A()
        {
            cout << " default actor " << endl;
        }

        static void* operator new(size_t size)
        {
            cout << " normal new " << endl;
            return ::operator new(size);
        }

        static void operator delete(void *ptr)
        {
            cout << " normal delete " << endl;
        }

        ~A()
        {
            cout << " default dctor " << endl;
        }

};

int main()
{
    {
        A *a = new A();
        delete a;
    }

    return 0;
}
