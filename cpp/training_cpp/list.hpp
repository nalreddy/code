#include "node.hpp"
#include<unordered_set>

template<typename T>
class List
{
    public :
        List(): mHead(nullptr), mLength(0) { }
        ~List();

        bool isEmpty() const;
        bool push_Front(const T x);
        bool push_Back(const T x);
        T pop_Front();
        T pop_Back();
        void print();
        size_t getLen() const;
        void reverse();
        bool search(const T x);
        int addSameSize(struct Node<T>*, struct Node<T>*);
        void addCarry(struct Node<T>*, struct Node<T>*, int &carry);
     private :
        struct Node<T>* mHead;
        size_t mLength;
};

template<typename T>
List<T> :: ~List()
{
    struct Node<T>* temp = mHead;

    if (isEmpty()) {
        std::cout << " list Dtor , list is empty " << std::endl;
        return;
    }

    struct Node<T>* end = mHead;
    while (end->mNext && (end->mNext != mHead))
    {
        end = end->mNext;
    }

    end->mNext = nullptr;

    while (temp)
    {

        mHead = mHead->mNext;
        delete temp;
        temp = mHead;
    }
}

template<typename T>
bool List<T> :: isEmpty() const
{
    return mHead == nullptr;
}

template<typename T>
size_t List<T> :: getLen() const
{
    return mLength;
}

template<typename T>
bool List<T> :: push_Front(const T x)
{
    struct Node<T>* temp = NULL;

    temp = new Node<T>(x);
    if (temp == nullptr)
        return false;

    temp->mNext = mHead;
    mHead = temp;
    mLength++;

    return true;
}

template<typename T>
T List<T> :: pop_Front()
{
    struct Node<T>* temp = mHead;

    if (isEmpty()) {
        std::cout << "List is empty " << std::endl;
    //assert ???
        return -1;
    }

    if (mHead->mNext) {
        mHead = temp->mNext;
    } else {
        mHead = nullptr;
    }

    T val = temp->mData;
    delete temp;
    mLength--;

    return val;
}

template<typename T>
bool List<T> :: push_Back(const T x)
{
    struct Node<T>* cur = mHead;

    if (isEmpty()) {
        mHead = new Node<T>(x);
        if (mHead == nullptr)
            return false;
        mLength++;
        return true;
    }
  
    while (cur->mNext)
    {
        cur = cur->mNext;
    }

    cur->mNext = new Node<T>(x);
    mLength++;

    return true;
}

template<typename T>
T List<T> :: pop_Back()
{
    struct Node<T>* cur = mHead;
    struct Node<T>* prev = nullptr; 

    if (isEmpty()) {
        std::cout << "List is empty " << std::endl;
        return -1;
    }
  
    while (cur->mNext)
    {
        prev = cur;
        cur = cur->mNext;
    }
    T val = cur->mData;
    if (!(cur == mHead)) 
        prev->mNext = nullptr;
    else 
        mHead = nullptr;

    delete cur;
    mLength--;

    return val;
}


template<typename T>
void  List<T> :: print()
{
    struct Node<T>* temp = mHead;

    if (!temp) {
        std::cout << " print List is empty" << std::endl;
        return;
    }

    while (temp)
    {
        std::cout << temp->mData << "  ";
        temp = temp->mNext;
        // if cycle break;
        if (temp == mHead)
            break;
    }

    std::cout << std::endl;
}

template<typename T>
void List<T> :: reverse()
{
    struct Node<T>* cur = mHead;
    struct Node<T>* next;
    struct Node<T>* prev = nullptr;

    if ( isEmpty()) return;

    while (cur)
    {
        next = cur;
        cur = cur->mNext;
        next->mNext = prev;
        prev = next;
    }
    mHead = prev;
}

template<typename T>
bool List<T> :: search(const T val)
{
    struct Node<T>* cur = mHead;

    if (isEmpty())
        return false;

    while (cur)
    {
        if (cur->mData == val)
            return true;
        cur = cur->mNext;
    }

    return false;
}
template<typename T>
void List<T> :: addCarry(struct Node<T>* cur1, struct Node<T>* cur2, int &carry)
{
    if (cur1 == cur2) return;

    addCarry(cur1->mNext, cur2, carry);

    int val = cur1->mData + carry;
    push_Front(val % 10);
    carry = val/10;
}


