#include<iostream>

using namespace std;

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
};

A *A :: a = NULL;

int main()
{
    A *a = A :: getobject();
    A *b = A :: getobject();

    return 0;
}


