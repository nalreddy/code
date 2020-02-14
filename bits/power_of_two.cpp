#include<iostream>

using namespace std;

inline bool isPowerOfTwo(size_t v) {
        return (v && !(v & (v - 1)));
}

int main()
{
    std::cout << isPowerOfTwo(3072);
    return 0;
}

