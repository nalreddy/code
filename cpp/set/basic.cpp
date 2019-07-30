#include<iostream>
#include<set>

using namespace std;

class A
{
    public:
        A(int _x) { x = _x; }
        ~A(){ };
        bool operator ==(A& a)
        {
            return this->x == a.x;
        }
    private:
        int x;
};

typedef std::set<A> Test;
int main()
{
    A a(10);
    A b(12);

    cout <<  (a == b);
    Test set;
    for(int i = 0; i< 10; i++)
    {
        A *a = new A(i);
        set.insert(a);
#if 0
        if(set.find(a) == set.end())
            cout << " not found ";
        else 
            cout << " found " <<  endl;
#endif
    }
    return 0;
}
