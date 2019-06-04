#include<iostream>
#include<list>
#include <iterator>

using namespace std;

int main()
{
    list<int> l;
    list<int> :: iterator it = l.begin();

#if 0
    l.push_back(1);
    l.push_back(10);
    l.push_back(11);
#endif

    
    while(l.end() != it) {
        cout << *it++;
    }

    return 0;
}
