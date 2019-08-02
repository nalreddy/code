#include<iostream>
#include<sstream>
#include<map>

using namespace std;

int main()
{
    std::stringstream ss;
    string word;
    map<string, int> mp;

    ss << 20 << endl;
    ss << 20 << endl;
    ss << 30 << endl;
    ss << 30 << endl;

    //ss.clear /ss.eof /ss.str
    while ( ss >> word) {
        mp[word]++;
        cout << word << endl;
    }
    map<string, int> ::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << endl;

    return 0;
}
