#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int main()
{
    std::string str ="hii";

    char *s = strdup(str.c_str());

    cout << "s " << s << endl;
    return 0;
}

