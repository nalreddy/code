#include<iostream>

using namespace std;

class Queue
{
    public:
        Queue(const unsigned int _cap): mFront(-1), mRear(-1), mCapacity(_cap), mSize(0)
        {
            mContainer = new int[mCapacity];
        }

        ~Queue()
        {
            delete mContainer;
        }

        bool enqueue(int item)
        {
            if (full())
            {
                cout << " queue full  " <<  " rear " << mRear << " front " << mFront << endl;
                return false;
            }
            mSize++;
            mRear = (mRear + 1) % mCapacity;
            if (mFront == -1)
                mFront++;
            mContainer[mRear] = item;
            cout << " inserted " << item  << " at Rear " << mRear << " front " << mFront << endl;
            return true;
        }

        bool dequeue()
        {
            if (empty())
            {
                cout << " queue empty " << "Rear "  << mRear << " front " << mFront <<  endl;
                return false;
            }
            int item = mContainer[mFront];
            cout << " deleted " << item  << " rear " << mRear << " front " << mFront << endl;
 
            if (mFront == mRear)
            {
                mFront = -1;
                mRear = -1;
            } else {

                mFront = (mFront + 1) % mCapacity;
            }
            mSize--;
           return true;
        }

        void display()
        {
        }

        bool full()
        {
            return (mFront == 0) && (mRear == mCapacity -1) || mRear == mFront - 1;
        }

        bool empty()
        {
            return mFront == -1;
        }

        void test()
        {
            if (full())
                cout << "full"<< endl;

            if (empty())
                cout << "empty"<< endl;
        }

        unsigned int size() { return mSize; }
        int front() {  return mContainer[mFront]; }
        int rear() {  return mContainer[mRear]; }

    private:
        int mFront;
        int mRear;
        unsigned int mCapacity;
        unsigned int mSize;
        int *mContainer;
};

int main()
{
    Queue q(3);
    q.test();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.test();
    q.dequeue();
    q.test();
    q.dequeue();
    q.test();
    q.dequeue();
    q.test();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.test();


    return 0;
}
