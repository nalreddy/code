#include<iostream>
#include<list>

using namespace std;

class R
{
    public :
        void set_val(int v)
        {
            val = v;
        }

        void reset()
        {
            val = 0;
        }

    private :
        int val;
};

class A
{
    private :
        A()
        {
            cout << "default constuctor "<< endl;
        }
    public :
       static A *a;

       static A*  getobject()
        {
            if (a == NULL) {
                cout << "singleton created"<< endl;
                return a = new A();
            } else {
                cout << "only one object gets created"<< endl;
                return NULL;
            }
        }
       R * get_resource() {
           if(list.empty())
              return new R;
           else {
               R *r = list.front();
               list.pop_front();
               return r;
           }
       }

       void return_r(R *r){
           r->reset();
           list.push_back(r);
       }
       std :: list<R *> list;
};

A *A :: a = NULL;

int main()
{
    A *a = A :: getobject();


    R *r1 = a->get_resource();
    R *r2 = a->get_resource();

    if(a->list.empty())
        cout << "empty()" << endl;

    a->return_r(r1);

    if(a->list.empty())
        cout << "empty()" << endl;


    return 0;
}


