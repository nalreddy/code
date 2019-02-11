#include<iostream>
using namespace std;

template<class T>
class SmartPtr
{
    public:
        SmartPtr(T* ptr = nullptr ) : mPtr(ptr) 
        { 
            cout << "Smart ctor called \n";
        }

        ~SmartPtr()
        {
            cout << "Smart dtor called \n";
            delete mPtr;
        }

        SmartPtr(SmartPtr& sPtr)
        {
            mPtr = sPtr.mPtr;
            sPtr.mPtr = nullptr;
            cout << "copy ctor called \n";
        }

        SmartPtr& operator = (SmartPtr& sPtr)
        {
            //seft assignment
            if (&sPtr == this) return *this;

            delete mPtr;

            mPtr = sPtr.mPtr;
            sPtr.mPtr = nullptr;
            cout << " assigment ctor called \n";
            return *this;
        }

        bool isNull () const { return mPtr == nullptr; }
        T& operator *() { return *mPtr; }
        T* operator ->() { return mPtr; }

    private:
        T* mPtr;
};

int main()
{
    SmartPtr<int> p1(new int(1));
    SmartPtr<int> p2; //(p1);

    p2 = p1;

    if(p1.isNull()) cout << "p1 null \n";
    if(p2.isNull()) cout << "p2 null \n";


    return 0;
}

