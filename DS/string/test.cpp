#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str = "abc";

    str[0] = 'x';

    string s2 = str + " dfdf";
    cout << "str " << s2;
    return 0;
}
