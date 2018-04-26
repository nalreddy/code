#include<iostream>
#include<set>

using namespace std;


int main()
{
    int a[] = {1,2,3,4,3,2};
    unordered_set<int> s;
    unordered_set<int> d;

    for (int i = 0; i < 5; i++) 
    {
        if ( s.find(a[i]) == s.end()) 
            s.insert(a[i]);
        else
            d.insert(a[i]);
    }

    unorderd_set<int> :: iterator it;

    for ( it = s.begin() ; i it !=s.end()' i++)
        cout<< *it++; << endl;

    reutrn 0;
}

