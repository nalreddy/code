#include<iostream>


using namespace std;

int split(char *str, char d, char **ptr)
{
    int count = 1;
    int token_len = 1;

    //str null return -1
    // str len = 1 return 1 same string;
    // if delemeter more thatn one character ???

    char *p = str;

    while (*p != '\0')
    {
        if (*p == d)
            count++;
        p++;
    }

    cout << " number of strings  " << count << endl;

    *ptr = (char **) malloc(sizeof(char *) * count);

    // exit if it fails to alloc

    p = str;
    int i = 0;
    int token_len = 0;
    while (*p != '\0')
    {
        if (*p  == d) {
            (*ptr)[i] = (char *) malloc(sizeof(char) * token_len);
            token_len = 0;
            i++;
        }
        p++;
        token_len++;
    }

    (*ptr)[i] = (char *) malloc(sizeof(char) * token_len);
    //exit memory 


}


