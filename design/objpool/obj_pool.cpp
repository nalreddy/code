#include<iostream>
#include<list>

using namespace std;

class Resource
{
    public:
        Resource(int val = 0) : val(val)
        {
        }

        void set(const int _val)
        {
            val = _val;
        }

        int get() const
        {
            return val;
        }

        void reset()
        {
            val = 0;
        }

    private:
        int val;
};

class Pool
{
    public:

        static Pool* getInstance()
        {
            if (!pool_instance) return new Pool();

            return pool_instance;
        }

        Resource* getResource()
        {
            if (list.empty())
            {
                return new Resource();
            }

            Resource* r = list.front();
            list.pop_front();
            return r;
        }

        void returnResource(Resource* r)
        {
            r->reset();
            list.push_back(r);
        }

    private:
        static Pool* pool_instance;
        std::list<Resource*> list;
};

Pool* Pool::pool_instance = NULL;

int main()
{
    Pool *p = Pool::getInstance();


    Resource *r = p->getResource();
    r->set(1);
    p->returnResource(r);

    cout << " val " << r->get() << endl;


    return 0;
}
