#include<iostream>

using namespace std;

bool pattern_search(string str, string pat)
{
    int i = 0, j = 0;

    for ( i = 0; i < str.length(); i++) {
        for ( j = 0; j < pat.length(); j++) {
             if(str[i+j] != pat[j])
                 break;
        }
        if ( j == pat.length())
            return true;
    }
    return false;
}


int main()
{
    string str = pattern_search("narayan reddy nallamilli", "r") ? "Found" : "not found";
    cout << str << endl;

    return 0;
}
