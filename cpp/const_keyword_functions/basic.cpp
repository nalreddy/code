#include<iostream>

using namespace std;

void get() const
{
    for (int i = 0; i < 10; i++)
        std::cout << " i  " << i << std::endl;
}

int main()
{
    get();

    return 0;
}
