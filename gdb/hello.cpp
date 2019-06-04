#include<iostream>

using namespace std;

int f2(int a, int b)
{
    int sum = 0;

    sum = a + b;

    return sum;
}
int f1(int a, int b)
{
    int ret = 0;

    ret = f2(a, b);

    return ret;
}

int main()
{
    int a = 2, b = 3, result = 0;

    result = f1(a, b);

    cout << " sum = " << result;
    return 0;
}
