#pragma once
#include<iostream>
#include <string>
#include "mysha.h"

using namespace std;

int main()
{
    string src = "abc";
    size_t len = 0;
    char* dest = new char[src.length()];

//    void (*const func)(const uint8_t* _input, const size_t _inputLen, uint8_t* _output, size_t* _outLen) = &sha1;
    init_sha(sha1, reinterpret_cast<const uint8_t*>(src.c_str()), src.length() , reinterpret_cast <uint8_t*>(dest) , &len);
    //sha1(reinterpret_cast<const uint8_t*>(src.c_str()), src.length() , reinterpret_cast <uint8_t*>(dest) , &len);

    std::cout << "out " << dest << " len " << len << std::endl;

    delete dest;
    return 0;
}

