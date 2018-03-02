#include<iostream>


using namespace std;


class A 
{
    private :
        int x;
    public :

        A()
        {
            cout << "default constructor " << endl;
            x = 10;
        }

        void print()
        {
            for ( int i = 0; i < x; i++) 
            {
                cout << "i = " << i << endl;
            }
        }

        void get_seg()
        {
            char *ptr = 0;

            *ptr = 3;
        }
};

int main()
{
    A a;
    
    a.print();

    return 0;
}
