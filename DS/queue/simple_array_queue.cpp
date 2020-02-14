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
                cout << " queue full  " << endl;
                return false;
            }
            mSize++;
            mRear++;
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
                cout << " queue empty " << endl;
                return false;
            }
            mSize--;
            int item = mContainer[mFront];
            cout << " deleted " << item  << " rear " << mRear << " front " << mFront << endl;
            mFront++;
            return true;
        }

        void display()
        {
        }

        bool full()
        {
            return mRear == mCapacity -1;
        }

        bool empty()
        {
            return (mFront == -1 || mFront == mRear + 1);
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
    Queue q(4);
/*
    q.test();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.test();
    q.dequeue();
    q.test();
    q.dequeue();
    q.test();
    q.dequeue();
    q.test();
    q.dequeue();
    q.test();
*/
    q.test();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.test();
    q.dequeue();
    q.test();
    q.dequeue();
    q.test();
    q.dequeue();
    q.test();
    q.dequeue();
    q.test();
    q.enqueue(3);
    q.test();
    q.dequeue();
    q.test();
  q.dequeue();
    q.test();



    return 0;
}
