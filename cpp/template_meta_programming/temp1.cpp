#include<iostream>

using namespace std;

template<typename T>
class A
{
    public:
        A()
        {

        }
        void print();
    private:
        T x;
};

template<typename T>
void A<T>::print()
{
    cout << "void " << endl;
}

int main()
{

    return 0;
}
