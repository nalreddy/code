#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

template<class C, class Pred>
void algo(C c&, Pred p&)
{
    sort(c.begin(), c.end(), p);
}

int main()
{
    vector<int> v = {3,4,1,8,6,5,9};

    return 0;
}

