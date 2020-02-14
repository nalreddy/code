// Sample program to show that memmove() is better than memcpy() 
// when addresses overlap. 
#include<iostream>
#include <stdio.h> 
#include <string.h> 

using namespace std;

void* mymove(char* dst, const char* src, unsigned long cnt)
{
    int temp = cnt;
    if(src + temp < dst)
    {
        memcpy(dst, src, cnt);
        return dst;
    }

    while(cnt > 0)
    {
        *(dst + cnt) = *(src + cnt);
        cnt--;
        
    }
    return dst;
}
int main() 
{ 
    char csrc[100] = "abcdefg"; 
//    memmove(csrc+5, csrc, strlen(csrc)+1); 
//    memcpy(csrc+1, csrc, strlen(csrc)+1); 
    char* dst = (char*) mymove(csrc+2, csrc, strlen(csrc) + 1);
//    printf("%s", csrc); 
    cout << dst << endl;
    cout << csrc << endl;

    return 0; 
} 

