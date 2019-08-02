#include<iostream>
#include<vector>

using namespace std;

int lcs(vector<int> v, int n)
{
    int *inc = new int[n];

    for (int i = 0; i < v.size(); i++) {
        inc[i] = 1;
        for (int j= 0; j < i; j++) {
            if( v[i] > v[j] && (inc[i] < inc[j] + 1)) {
                inc[i] = inc[j] + 1;
            }
        }
    }

    int max = -1;
    for (int i = 0; i < v.size(); i++) {
        if(max < inc[i])
            max = inc[i];
    }
    return max;
}

int main()
{
    vector<int>  v(5);
    v[0] = -5;
    v[1] = -4;
    v[2] = -3;
    v[3] = -2;
    v[4] = -1;

    cout<<v.size();
    cout << lcs(v, v.size());

    return 0;
}
