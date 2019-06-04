#include<iostream>
#include<sstream>

using namespace std;

int main()
{
    std::stringstream ss;
    string word;

    ss << 20 << endl;
    ss << 30;
    cout << ss.str() << endl;
    while ( ss >> word)
        cout << word << endl;

    return 0;
}
