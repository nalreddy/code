
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Vol
{
uint8_t mSizeExtention:1;
uint8_t mSize:3;
};


uint8_t getSize(struct Vol v){ return (v.mSizeExtention << 3) | v.mSize; }

void setSize(struct Vol* v, uint8_t size)
{
    v->mSizeExtention = (size >> 3);
    v->mSize = (size & 0x7);
}

void printVal(uint8_t s, struct Vol v)
{
    printf("orgin size =%d  exttion %d size = %d \n", s, v.mSizeExtention, v.mSize); 
    printf("size = %d \n", getSize(v));
}

int main()
{
    struct Vol v1;
    uint8_t size[12] = {1,2,3,4,5,6,7,8,9,10,11,12};

    for (int i = 0; i < 12; i++)
    {
        setSize(&v1, size[i]);
        printVal(size[i], v1);
    }


    return 0;
}
