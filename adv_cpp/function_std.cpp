#include <bits/stdc++.h> 

using namespace std; 

// Function to print vector 
void printVector(vector<int> v) 
{ 
    // lambda expression to print vector 
    for_each(v.begin(), v.end(), [](int i) 
            { 
            std::cout << i << " "; 
            }); 
    cout << endl; 
}

int main() 
{ 
    vector<int> v {4, 1, 3, 5, 2, 3, 1, 7}; 

    printVector(v); 
}
