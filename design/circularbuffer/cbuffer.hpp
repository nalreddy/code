#include<array>
template<class T, const size_t CAPACITY>
class CBuffer
{
    public :
        CBuffer() : mHead(-1), mTail(-1) {}
        ~CBuffer() {}
        bool isFull() const
        {
            if ((mHead + 1) % CAPACITY == mTail)
                return true;
            else
                return false;
        }
        bool isEmpty() const
        {
            if (mHead == mTail) return true;
            else return false;
        }
        bool push(const T item);
        bool pop(T& item);
    private:
        std::array<T, CAPACITY> mBuffer;
        static const size_t mCapacity = CAPACITY;
        size_t mHead;
        size_t mTail;
};
