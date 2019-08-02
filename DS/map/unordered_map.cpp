#include<iostream>
#include<unordered_map>

using namespace std;

int main() 
{
    unordered_map<int, int> ump;

    for (int i = 0; i < 10; i++)
    {
        ump[i] += 1;
    }
    unordered_map<int, int> :: iterator it;

    for (it = ump.begin(); it != ump.end(); ++it) {
        cout << (*it).first << " " << (*it).second << endl;
    }
    return 0;
}
