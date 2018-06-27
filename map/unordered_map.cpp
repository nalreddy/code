#include<iostream>
#include<unordered_map>

using namespace std;

int main() 
{
    unordered_map<int, int> ump;

    ump[4] = 14;
    ump[1]++;
    ump[2] = 12;
    ump[3] = 13;
    ump[5] = 15;
    
    unordered_map<int, int> :: iterator it;

    for (it = ump.begin(); it != ump.end(); ++it) {
        cout << (*it).first << " " << (*it).second << endl;
    }
    return 0;
}
