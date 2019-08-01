#include "cbuffer.hpp"

template<class T, const size_t CAPACITY>
bool CBuffer<T, CAPACITY>::push(const T item)
{
    if (isFull())
    {
        return false;
    }

    if (-1 == mHead)
    {
        mTail = 0;
    }

    mHead = (mHead + 1) % CAPACITY;
    mBuffer[mHead] = item;

    return true;
}

template<class T, const size_t CAPACITY>
bool CBuffer<T, CAPACITY>::pop(T& item)
{
    if (isEmpty())
    {
        return false;
    }

    mTail = (mTail + 1) % CAPACITY;
    item = mBuffer[mTail];

    return true;
}
#if 0
int main()
{
    CBuffer<int, 5> buffer;
    buffer.push(1);

    return 0;
}
#endif
