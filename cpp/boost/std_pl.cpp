#include<iostream>
#include<functional>

using namespace std;

int main()
{
    int x = std::plus<int>()(1,2);
    cout << "val " << x;
    return 0;
}

