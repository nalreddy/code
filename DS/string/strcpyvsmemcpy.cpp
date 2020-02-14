#include<iostream>
#include<string.h>

using namespace std;

void dump(char* str)
{
    char* p = str;
    for(int i = 0; i < 5; i++)
    {
        printf("%2.2x ", *p);
        ++p;
    }
    cout << endl;
}

int main()
{
    char src[5] = {'a', 'b', '\0', 'c'};//"ab\0c";
    char dst[5];
    char memdst[5];

    strcpy(dst, src);
    memcpy(memdst, src, 5);

    cout << " dst " << dst <<  " memdst " << memdst << endl;
    dump(dst);
    dump(memdst);

    return 0;
}
