
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Student {
    uint64_t mVolume       : 4;
    uint64_t mTier         : 3;
    uint64_t mSize         : 3;
    uint64_t mMiniVolumeId : 3;
    uint64_t mAllocCount   : 3;
    uint64_t mExtention    : 1;
    uint64_t mUnUsed       : 47;

};

uint8_t getSize(struct Student st)
{
    uint8_t temp = 8;
    if (st.mExtention)
    {
        return temp | st.mSize;
    }
    else
    {
        return st.mSize;
    }

}

void setSize(struct Student* st, uint8_t size)
{
    if ( size > 8)
    {
        st->mExtention = 1;
    }
    else
    {
        st->mExtention = 0;
    }
    st->mSize = size & 7;
    printf(" testsize = %d  = %d \n" ,size, size & 7);
}

int main()
{
    struct Student st= {1,2,0,3,5, 0};
    struct Student sp; //= {1,2,3,3,5,1};

    setSize(&st, 3);

    sp.mVolume = 1;
    sp.mTier = 2;
    setSize(&sp, 11);
    sp.mMiniVolumeId = 3;
    sp.mAllocCount = 3;
    sp.mUnUsed = 0;
    printf("st %d \n ", getSize(st));
    printf("sp %d \n ", getSize(sp));

    return 0;
}
