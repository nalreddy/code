#include<iostream>

using namespace std;

int f(int *x)
{

    return  *x;
}

int main()
{
    int p = 10;

    int (*fp)(int*) = f;

            cout << " val; "  << fp(&p);
#if 0
    int v[] = {1,2,3,4,5};

    for(auto& x : v)
    {
        cout << x << "\n";
        ++x;
    }
#endif

    return 0;
}
