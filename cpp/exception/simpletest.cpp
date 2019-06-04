#include<iostream>

using namespace std;

void test()
{
    try 
    {
        throw "catch me if you can ";
    }
    catch (...)
    {
        cout << " Got you \n"<< endl;
    }
}

int main()
{
    test();
    return 0;
}
