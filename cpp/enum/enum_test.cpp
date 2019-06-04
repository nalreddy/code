#include<iostream>

using namespace std;


class A
{
    private:
        enum { arr_size = 5};

        int arr[arr_size];
};

int main()
{
    A a;

    return 0;
}
