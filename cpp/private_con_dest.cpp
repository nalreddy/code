#include<iostream>

using namespace std;

class A
{
    private :
        A ()
        {
            x = 10;
            cout << "default constuctor "<< x << endl;
            
        }
    public :
        int x;
        friend class B;
};

class B
{
    public :
        A * getobject()
        {
            return new A;
        }
};

int main()
{
    B b;
    b.getobject();

    return 0;
}


