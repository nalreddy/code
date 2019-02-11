#include<iostream>
using namespace std;

template<class T>
class SmartPtr
{
    public:
        SmartPtr(T* ptr) : mPtr(ptr) 
        { 
            cout << "Smart ctor called \n";
        }

        ~SmartPtr()
        {
            cout << "Smart dtor called \n";
            delete mPtr;
        }

        T& operator *() { return *mPtr; }
        T* operator ->() { return mPtr; }

    private:
        T* mPtr;
};

int main()
{
    SmartPtr<int> p1(new int(1));

    cout << " *p1  " << *p1 << endl;

    return 0;
}

