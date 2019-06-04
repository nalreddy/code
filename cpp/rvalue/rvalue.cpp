#include<iostream>
#include<algorithm>

using namespace std;

class A
{
    public:
        explicit A(size_t len) : mLen(len), mData(new int[len])
        {
            cout << " normal  ctor " << endl;
        }

        ~A()
        {
            if (mData != NULL)
            {
                delete[] mData;
            }
            cout << " dtor " << endl;
        }

        A(const A& other):mLen(other.mLen), mData(new int[other.mLen])
        {
            cout << " copy ctor " << endl;
            std::copy(other.mData, other.mData + mLen, mData);
        }

        A& operator =(const A& other)
        {
            if (this != &other)
            {
                delete mData;
                mLen = other.mLen;
                mData = new int[mLen];
                std::copy(other.mData, other.mData + mLen, mData);
            }
            cout << "  assing operator " << endl;
            return *this;
        }

        A(A&& other):mLen(other.mLen)
        {
            cout << "rlvaue copy ctor " << endl;
            mData  = other.mData;
            other.mData = NULL;
            other.mLen = 0;
        }

        A& operator =(A&& other)
        {
            if (this != &other)
            {
                delete mData;
                mLen = other.mLen;
                mData  = other.mData;
                other.mLen = 0;
                other.mData = NULL;
            }
            cout << "rvalue assing operator " << endl;
            return *this;
        }


    private:
        int* mData;
        int mLen;
};

int main()
{
    A a1(10);
    A a2 = std::move(a1);

    return 0;
}
