#include<list>

class Store
{
    public:
        Store() {}
        virtual ~Store() {}

        void put(const size_t x);
        size_t get();

        inline size_t size() { return  mList.size(); }
        inline size_t empty() { return (0 == size()); }

        //danger
        void show();
    private:
        typedef std::list<size_t > List;
        List mList;
};

void Store::show()
{
    std::list<size_t>::iterator itr = mList.begin();

    for(;  itr != mList.end(); itr++)
        std::cout << *itr <<std::endl;
}
void Store::put(const size_t x)
{
    mList.push_front(x);
}

size_t Store::get()
{
    size_t elem = 0; // = mList.pop_front();
    std::list<size_t>::iterator itr = mList.begin();
    elem = *itr;
    mList.erase(itr);

    return elem;
}
