#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

struct greater
{
    const int val;
    greater(const int v): val(v) { }
    bool operator()(const pair<string , int>& r) { return r.second > val; }
};

int main()
{
    map<string, int> mp;

    mp["one"] = 1;
    mp["fourone"] = 41;
    mp["two"] = 2;

    struct greater  gt(40);

    int x = find_if(mp.begin(), mp.end(), gt);
    cout << " x = " << x << endl;

    return 0;
}
