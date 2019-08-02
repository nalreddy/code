#include<iostream>

using namespace std;

#if 0
T * p = reinterpret_cast<T*>(mAddress);
for(uint64_t i=0; i<count; i++)
{
    new (p) T();
    p++;
}

#endif
class A
{
    public:

        A()
        {
            cout << " default actor " << endl;
        }

        static void* operator new(size_t size, bool custom)
        {
            if (custom)
            {
                cout << " A custom " <<  endl;
            }
            cout << " normal new " << endl;
            return ::operator new(size);
        }

#if 0
        static void* operator new(size_t size)
        {
            cout << " normal new " << endl;
            return ::operator new(size);
        }

        static void operator delete(void *ptr)
        {
            cout << " normal delete " << endl;
        }
#endif

        ~A()
        {
            cout << " default dctor " << endl;
        }

};

int main()
{
    {
        A *a = new (true) A();
        delete a;
    }

    return 0;
}
