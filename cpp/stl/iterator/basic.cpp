#include<iostream>
#include<list>

using namespace std;

int main()
{
    list<int> l;

    for (int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }

    list<int> :: iterator it = l.begin();

    while(it != l.end())
    {
        cout << "i = " << *it << endl;
        it++;
    }
    return 0;
}
