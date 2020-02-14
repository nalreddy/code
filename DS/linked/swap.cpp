// CPP program to illustrate the 
// list::splice() function 
#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    // initializing lists 
    list<int> l1; // = { 1, 2, 3 }; 
    list<int> l2 = { 4, 5, 6 }; 
#if 0
    list<int> l3 = { 6, 7, 8 }; 

    // transfer all the elements of l2 
    l1.splice(l1.begin(), l2); 

    // at the beginning of l1 
    cout << "list l1 after splice operation" << endl; 
    for (auto x : l1) 
        cout << x << " "; 

    // transfer all the elements of l1 
    l3.splice(l3.end(), l1); 

#endif
    l1.swap(l2);

    cout << " List 1 " << endl;
     for (auto x : l1) 
        cout << x << " "; 

     cout << " \n" << endl;

    cout << " List 2 ";
    for (auto x : l2) 
        cout << x << " "; 

    return 0; 
} 

