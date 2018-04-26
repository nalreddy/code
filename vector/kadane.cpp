#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vt(5);
    vector<int> :: iterator it;

//
//    for ( int i = 0 ; i < 5; i++ ) {
//        vt.push_back(i);
//    }
//
    vt[0] = 1;
    vt[1] = 3;
    vt[2] = -2;
    vt[3] = 1;
    vt[4] = -1;
    int max_ending_here = 0, max_so_far = 0;

    for ( it = vt.begin();  it != vt.end(); it++) {
        max_ending_here = *it + max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
        else 
            max_so_far = max_ending_here > max_so_far ? max_ending_here : max_so_far;

       // cout << *it << endl;
    cout << max_ending_here << max_so_far << endl;
    }

    cout << max_ending_here << max_so_far << endl;


    return 0;
}
