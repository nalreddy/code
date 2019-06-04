#include<iostream>

using namespace std;

unsigned char test[] = {
    0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x31, 0x32, 0x33,
    0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
    0x37, 0x0a
};
unsigned int test_len = 26;

typedef enum datatype
{
    compressed,
    uncompressed
} datatype;

typedef enum testtype
{
    positive,
    negative
} testtype;

template<size_t uncompressedsize, size_t compressedsize, datatype dt, testtype ttype> 
    struct base
{
    const size_t uncompsize = uncompressedsize;
    const size_T compsize = compressedsize;
    datatype data = dt;
    testtype test = ttype;
};

template<size_t uncompressedsize, size_t compressedsize, datatype dt, testtype ttype>
    struct derived : public base<uncompressedsize, compressedsize, dt, ttype>
{

};

#define DEFINE_DATA(rawsize, compsize, type,array, testtype)    \
    template<> struct derived<rawsize,compszie, type,testtype>: \
         public base<rawsize,compszie, type,testtype>           \
    {                                                           \
        static const uint8_t* addr() { return &array[0]}        \
        static const size_t size() { return sizeof(array);}     \
    };                                                          \

typedef derived<rawsize, compsize, type, testtype> desc##rawsize##compsize##type##testtype;

DEFINE_DATA(8,3, compressed, test, positive);
DEFINE_DATA(8,3, compressed, test, negative);
DEFINE_DATA(8,8, uncompressed, test, negative);

int main()
{
    desc84compressedpositive dt;

    return 0;
}
