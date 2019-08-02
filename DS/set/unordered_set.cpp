#include<iostream>
#include<unordered_set>

using namespace std;

int main()
{
    unordered_set<int> unset;


    unset.insert(1);
    unset.insert(1);
    unset.insert(1);
    unset.insert(2);
    unset.insert(1);

    unordered_set<int> :: iterator it;

    for (it = unset.begin(); it != unset.end() ; it++) {
        cout << *it << endl;
    }
    return 0;
}

