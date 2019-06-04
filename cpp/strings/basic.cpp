#include<iostream>
#include<string>

using namespace std;

int main()
{
#if 0
    char* p = "abcd";
//    p[0] = 'x';
    p = "ijkl";

    char a[] = "pqrs";

    a[0] = 'l';

    a = "rfgt";
#endif
    const char* p = "abcd";
//    p[0] = 's';
    p = "fgfgf";
    char *const a = "dfgfs";

    a[0] = 'h';


    return 0;
}

