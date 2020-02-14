#include<iostream>
#include<stdlib.h>

using namespace std;

class A
{
    public :
        A()
        {
            cout << "  Default  ctor " << endl;
        }
        ~A()
        {
            cout << "  Default  dtor " << endl;
        }
};

int main()
{
    A *a = static_cast<A*> (malloc(10 * sizeof(class A)));
    A *pa = new A[10];

    free(a);

   // delete []pa;
    delete pa;

    return 0;
}
