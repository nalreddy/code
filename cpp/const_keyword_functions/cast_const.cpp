#include<iostream>

using namespace std;

class A
{

    public:
        A()
        {
            for (int i = 0; i < 10; i++)
            {
                arr[i] = i;
            }
            cout << "ctor called "<< endl;
        }

        const int& operator[](int pos) const
        {
            return arr[pos];
        }

        int& operator[](int pos)
        {
            return const_cast<int &> (static_cast<const A& >(*this) [pos]);
        }


    private:

    int arr[10];
};

int main()
{
    A a;
    const A c;

    cout << a[2];
    cout << c[2];
    return 0;
}
