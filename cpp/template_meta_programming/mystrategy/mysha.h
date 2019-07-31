#ifndef MYSHA_H
#define MYSHA_H
#endif

#include<stdint.h>

void sha1(const uint8_t* _input, const size_t _inputLen, uint8_t* _output, size_t* _outLen);
void sha2(const uint8_t* _input, const size_t _inputLen, uint8_t* _output, size_t* _outLen);

typedef void (*const func)( const uint8_t* _input, const size_t _inputLen, uint8_t* _output, size_t* _outLen);

void init_sha(func, const uint8_t* _input, const size_t _inputLen, uint8_t* _output, size_t* _outLen);
