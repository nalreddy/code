#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vt;

    vt.push_back(1);
    vt.push_back(2);
    vt.push_back(3);

    vector<int> :: iterator iv = vt.begin();

    while (iv != vt.end()) {
        cout << "value = v "<< *iv++ << endl;
    }
    
    return 0;
}
