#include<iostream>
#include<map>

using namespace std;

class Node
{
    public:
        Node(int key, int value, Node *next, Node *prev):
            mKey(key), mValue(value), mNext(next), mPrev(prev)
        { 
        }

        Node(int key, int value): mKey(key), mValue(value), mNext(NULL), mPrev(NULL)
        {
        }

        ~Node() { }
#if 0
        int get_key() { return mKey; }
        int get_value() { return mValue; }

        Node* get_next() { return mNext; }
        Node* get_prev() { return mPrev; }

        void set_next(Node *node)
        {
            mNext = node;
        }

        void set_prev(Node *node) 
        {
            nPrev = node;
        }
#endif
        int mKey;
        int mValue;
        Node *mNext;
        Node *mPrev;
};

class List
{
    public:
        List(Node *front, Node *rear): mFront(front), mRear(rear) { }

        List(): mFront(NULL), mRear(NULL) { }

        ~List() { }

        Node* get_node(int key, int value)
        {
            return new Node(key, value);
        }

        Node* get_rear() 
        {
            return mRear;
        }

        void remove_rear()
        {
            if(!mRear) return;

            if(mFront == mRear) 
            {
                delete mRear;
                mRear = mFront = NULL;
            }

            Node* temp = mRear;
            mRear = mRear->mPrev;
            mRear->mNext = NULL;
            delete temp;
        }

        Node* add_to_front(int key, int value)
        {
            Node* node = new Node(key, value);
            
            if(!mFront && !mRear) 
            { 
                mFront = mRear = node;
            } else {
                mFront->mPrev = node;
                node->mNext = mFront;
                node->mPrev = NULL;
                mFront = node;
            }

            return node;
        }

        void move_to_head(Node *node)
        {
            if(node == mFront) { return; }
        
            if(node == mRear) 
            { 
                mRear = mRear->mPrev;
                mRear->mNext = NULL;
            } else {
                node->mPrev->mNext = node->mNext;
                node->mNext->mPrev = node->mPrev;
            }

            mFront->mPrev = node;
            node->mNext = mFront;
            node->mPrev = NULL;
            mFront = node;
        }

        bool is_empty() { return mRear == NULL; }

    private:
        Node *mFront;
        Node *mRear;
};

class Cache
{
    private:
        size_t mSize;
        size_t mCap;
        List *mPageList;
        map<int, Node*> mPageMap;

    public:
        Cache(size_t cap) 
        {
            mCap = cap;
            mSize = 0;
            mPageList = new List();
            map<int, Node*> mPageMap;
        }
        ~Cache() 
        {
            map<int, Node*>::iterator it;

            for(it = mPageMap.begin(); it != mPageMap.end(); it++)
            {
                delete it->second;
            }
            delete mPageList;
        }

        int get(int key) 
        {
            if(mPageMap.find(key) == mPageMap.end())
            { 
                return -1;
            }

            int val = mPageMap[key]->mValue;

            mPageList->move_to_head(mPageMap[key]);
            return val;
        }
        
        void put(int key , int value)
        {
            if(mPageMap.find(key) != mPageMap.end())
            { 
               mPageMap[key]->mValue = value;
               mPageList->move_to_head(mPageMap[key]);
               return;
            }

            if( mSize == mCap ) {
               int k = mPageList->get_rear()->mKey;
               mPageList->remove_rear();
               mPageMap.erase(k);
               mSize--;
            }
            Node *node = mPageList->add_to_front(key, value);
            mSize++;
            mPageMap[key] = node;
        }
};

//making it template
//apply oops principles encapsulation etc
//create .hpps making it more modular and readable with comments
//write unite test cases
//indentation
