#pragma once
#include<stdio.h>
#include<string.h>
#include<stddef.h>
#include "mysha.h"

void sha1(const uint8_t* _input, const size_t _inputLen, uint8_t* _output, size_t* _outLen)
{
    memcpy((void *)_output, (void *)_input, _inputLen);
    *_outLen = _inputLen;

    printf("func %s _input =  %s _inputLen =  %ld  _output = %s  _outLen = %ld \n", __func__, _input, _inputLen, _output, *_outLen);
}

void sha2(const uint8_t* _input, const size_t _inputLen, uint8_t* _output, size_t* _outLen)
{
    memcpy((void *)_output, (void *)_input, _inputLen);
    *_outLen = _inputLen;

    printf("func %s _input =  %s _inputLen =  %ld  _output = %s  _outLen = %ld \n", __func__, _input, _inputLen, _output, *_outLen);
}

void init_sha(func funcptr/*void (*const func)( const uint8_t* _input, const size_t _inputLen, uint8_t* _output, size_t* _outLen)*/, const uint8_t* _input, const size_t _inputLen, uint8_t* _output, size_t* _outLen)
{
    funcptr(_input, _inputLen, _output, _outLen);
}
