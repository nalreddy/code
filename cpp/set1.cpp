#include<iostream>
#include<set>
#include<string>
int main()
{
    std::set<std::string> setOfNumbers;
 
    // Lets insert four elements
    setOfNumbers.insert("second");
    setOfNumbers.insert("first");
    setOfNumbers.insert("third");
    setOfNumbers.insert("first");
 
    // Only 3 elements will be inserted
    std::cout<<"Set Size = "<<setOfNumbers.size()<<std::endl;
 
    // Iterate through all the elements in a set and display the value.
    for (std::set<std::string>::iterator it=setOfNumbers.begin(); it!=setOfNumbers.end(); ++it)
        std::cout << ' ' << *it;
    std::cout<<"\n";
    return 0;
}
