#include<iostream>
#include<stdint.h>

using namespace std;

int main()
{
    uint64_t x = 1024 * 7;

    cout << " val " << (x >> 10) -1  << endl;
    return 0;
}
