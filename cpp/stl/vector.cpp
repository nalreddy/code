#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {

    vector<string> ss;

    ss.push_back("hi 10");
    ss.push_back("hi 20");
    ss.push_back("hi 30");

    int i;

    for (i = 0; i < ss.size(); i++)
    {
        cout << ss[i] << endl;
    }
    
    return 0;
}
