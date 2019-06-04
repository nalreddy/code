#include<iostream>
#include<memory>

using namespace std;

template<class T>
class SharedPool
{
    public:
        SharedPool(){}
        virtual ~SharedPool(){}

        void add(std::unique_ptr<T> t) {
            pool_.push(std::move(t));
        }

        std::unique_ptr<T> acquire() {
            assert(!pool_.empty());
            std::unique_ptr<T> tmp(std::move(pool_.top()));
            pool_.pop();
            return std::move(tmp);
        }

        bool empty() const {
            return pool_.empty();
        }

    private:
        std::stack<std::unique_ptr<T> > pool_;
};

int main()
{
    SharedPool<int> pool;

    pool.add(std::unique_ptr<int>(new int(42));
        
    {
     auto v = pool.acquire();
    }

    return 0;
}
