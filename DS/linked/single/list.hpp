#include "node.hpp"
#include<unordered_set>

//push,pop,reverse,cycle
//arthimatic add,subract,polynomial,mul
// convert from linked list to binary tree

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
        bool detectCycle();
        void makeCycle();
        void removeCycle();
        void addListLsb(const List<T> &l1, const List<T> &l2);
        void addListMsb(const List<T> &l1, const List<T> &l2);
        void operator=(const List<T> &l1);
        int addSameSize(struct Node<T>*, struct Node<T>*);
        void addCarry(struct Node<T>*, struct Node<T>*, int &carry);

     private :
        void unlinkCycle(struct Node<T>* slow, struct Node<T>* head);
        struct Node<T>* mHead;
        size_t mLength;
};


//need to optimize code, two traversals unncessary
template<typename T>
List<T> :: ~List()
{
    struct Node<T>* temp = mHead;

    if (isEmpty()) {
 //std::cout << " list Dtor , list is empty " << std::endl;
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
       // std::cout << "List is empty " << std::endl;
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
        //std::cout << "List is empty " << std::endl;
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
        //std::cout << " print List is empty" << std::endl;
        return;
    }

    while (temp)
    {
    //    std::cout << temp->mData << "  ";
        temp = temp->mNext;
        // if cycle break;
        if (temp == mHead)
            break;
    }

//    std::cout << std::endl;
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
bool List<T> :: detectCycle()
{
#if 0
    struct Node<T>* slow = mHead;
    struct Node<T>* fast = mHead;

    if (isEmpty()) return false;

    while (slow && fast && fast->mNext)
    {

        slow = slow->mNext;
        fast = fast->mNext->mNext;

        if (slow == fast) {
            std::cout << " found cycle " << std::endl;
            return true;
        }
    }

    return false;
#endif
    //with stl
    std::unordered_set<Node<T>* > set;

    struct Node<T>* cur = mHead;
    while (cur)
    {
        if (set.find(cur) != set.end()) {
            return true;
        }
        set.insert(cur);
        cur = cur->mNext;
    }
    return false;
}

template<typename T>
void List<T> :: makeCycle()
{
    struct Node<T>* cur = mHead;

    if (isEmpty()) return;

    while (cur->mNext)
    {
        cur = cur->mNext;
    }
    cur->mNext = mHead;
   // std::cout << "make cycle " << std::endl;
}


template<typename T>
void List<T> :: removeCycle()
{
#if 0    
    std::unordered_set<Node<T>* > set;

    struct Node<T>* cur = mHead;
    struct Node<T>* last;
    while (cur)
    {
        if (set.find(cur) == set.end()) {
            set.insert(cur);
            last = cur;
        } else {
            last->mNext = nullptr;
        }
        cur = cur->mNext;
    }
#endif
    struct Node<T>* slow = mHead;
    struct Node<T>* fast = mHead;

    if (isEmpty()) return;

    while (slow && fast && fast->mNext)
    {

        slow = slow->mNext;
        fast = fast->mNext->mNext;

        if (slow == fast) {
            unlinkCycle(slow, mHead);
            //std::cout << " found cycle " << std::endl;
        }
    }
}

template<typename T>
void List<T> :: unlinkCycle(struct Node<T>* loop_node, struct Node<T>* head)
{
    struct Node<T>* ptr1 = head;
    struct Node<T>* ptr2; 

    while (true)
    {
        ptr2 = loop_node;

        while (ptr2->mNext != loop_node && ptr2->mNext != ptr1)
        {
            ptr2 = ptr2->mNext;
        }

        if (ptr1 == ptr2->mNext) {
            break;
        }
        ptr1 = ptr1->mNext;
    }
    ptr2->mNext = nullptr;
}

template<typename T>
void List<T> :: operator=(const List<T> &l1)
{
    //don't want to overwrite
    if (!isEmpty())
        return;

    struct Node<T>* cur = l1.mHead;

    while (cur != nullptr)
    {
        push_Back(cur->mData);
        cur = cur->mNext;
    }
}

template<typename T>
void List<T> :: addListLsb(const List<T> &l1, const List<T> &l2)
{
    struct Node<T>* cur1 = l1.mHead;
    struct Node<T>* cur2 = l2.mHead;
    T carry = 0, val = 0;

    while ((cur1 != nullptr) || (cur2 != nullptr))
    {
        val = (cur1 != nullptr ? cur1->mData : 0) + (cur2 != nullptr ? cur2->mData : 0) + carry;
        carry = val/10;

        if (isEmpty()) {
            mHead = new Node<T>(val % 10);
        } else {
            push_Back(val % 10);
        }
        mLength++;

        cur1 = cur1 ? cur1->mNext : nullptr;
        cur2 = cur2 ? cur2->mNext : nullptr;
    }

    if (carry) {
        push_Back(carry);
    }
}

template<typename T>
int List<T> :: addSameSize(struct Node<T>* cur1, struct Node<T>* cur2)
{
    if (cur1 == nullptr)
        return 0;

    int carry = addSameSize(cur1->mNext, cur2->mNext);

    int val = 0;
    val = cur1->mData + cur2->mData + carry;
    carry = val/10;

    if (isEmpty()) {
        mHead = new Node<T>(val % 10);
        mLength++;
    } else {
        push_Front(val % 10);
    }
    return carry;
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

template<typename T>
void List<T> :: addListMsb(const List<T> &l1, const List<T> &l2)
{
    if (l1.isEmpty() && l2.isEmpty())
        return;

    if (l1.isEmpty()) {
        mHead = l2.mHead;
        mLength++;
        return;
    }

    if (l2.isEmpty()) {
        mHead = l1.mHead;
        mLength++;
        return;
    }

    size_t len1 = l1.getLen();
    size_t len2 = l2.getLen();

    struct Node<T>* cur1 = l1.mHead;
    struct Node<T>* cur2 = l2.mHead;
    int carry = 0;
    //same size
    if (len1 == len2) {
        carry = addSameSize(cur1, cur2);
    } else {
        int diff = abs(len1 - len2);

        if (len1 < len2) {
            cur1 = l2.mHead;
            cur2 = l1.mHead;
        }
        struct Node<T>* temp = cur1;
        for (; diff != 0; diff--) {
            temp = temp->mNext;
        }
        carry = addSameSize(temp, cur2);
        addCarry(cur1, temp, carry); 
    }

    if (carry) {
        push_Front(carry);
    }
}
