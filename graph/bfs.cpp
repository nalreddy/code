#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> adv[5];

    adv[0].push_back(1);
    adv[0].push_back(2);
    adv[0].push_back(3);
    adv[1].push_back(2);
    adv[1].push_back(3);
    adv[2].push_back(1);
    adv[2].push_back(3);
    adv[2].push_back(0);

    return 0;
}
