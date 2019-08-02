template<typename T>
struct Node 
{
    Node(): mNext(nullptr), mData(0) { }
    Node(const T data): mNext(nullptr), mData(data) { }

    T mData;
    Node<T>* mNext;
};
