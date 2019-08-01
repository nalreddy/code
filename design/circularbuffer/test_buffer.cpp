#include<iostream>
#include"cbuffer.hpp"

int main()
{
    CBuffer<int, 5>  buffer; // = new CBuffer<int, 10>();

    for (int i = 0; i < 5; i++)
        buffer.push(i);


    return 0;
}

