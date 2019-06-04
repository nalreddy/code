#include<iostream>
//#include<cstdint>
#include<stdint.h>

int main() {
    uint32_t  x : 2;
    
    x = 1;
    
    std::cout << "x = " << sizeof(x);

    return 0;
}
