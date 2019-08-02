/* strtok example */
#include<iostream>
#include <cstring>

using namespace std;

int main ()
{
    char str[] ="This,asample,string.";

    char * pch;
    pch = strtok (str," ,.-");
    while (pch != NULL)
    {
        cout << pch << endl;
        pch = strtok (NULL, " ,.-");
    }
    cout << str << endl;
    return 0;
}
