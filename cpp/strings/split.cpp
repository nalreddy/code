
#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp> 
using namespace std; 

int main() 
{ 
    string input("geeks:for:geeks"); 
    vector<string> result; 
    boost::split(result, input, boost::is_any_of(":")); 

    for (int i = 0; i < result.size(); i++) 
        cout << result[i].c_str() << endl; 
    return 0; 
} 
