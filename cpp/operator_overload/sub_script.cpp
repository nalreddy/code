#include<iostream>

using namespace std;

class A
{
    public:
        A(int* _ptr = NULL, int _size = 0)
        {
            if ( _size != 0)
            {
                ptr = new int [_size];
                for (int i = 0; i < _size; i++)
                    ptr[i] = _ptr[i];
                size = _size;
            }
        }

        ~A()
        {
            delete [] ptr;
        }

        int& operator[](int x)
        {
            return ptr[x];
        }

        void print()
        {
            for (int i = 0; i < size; i++)
            {
                cout << ptr[i] << " ";
            }
            cout << endl;
        }
    private:
        int *ptr;
        int size;
};


int main()
{
    int x[] = {1,2,3,4,5};

    A a(x, 5);

    a.print();

    a[0] = 6;

    a.print();

    return 0;
}
