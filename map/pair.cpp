#include<iostream>
#include<map>

using namespace std;

int main()
{
    pair<int, int> p;
    map<int,int> mp;

    mp.insert(make_pair(1,2));
    mp.insert(pair<int,int>(11,22));

    p.first = 1;
    p.second = 2;

    cout<< p.first << "  " << p.second << endl;
    return 0;
}
