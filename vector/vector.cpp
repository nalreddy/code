#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vt;
    vector<int> :: iterator it;


    for ( int i = 0 ; i < 5; i++ ) {
        vt.push_back(i);
    }


    for ( it = vt.begin();  it != vt.end(); it++) {
        cout << *it << endl;
    }


    return 0;
}
