#include<iostream>

using namespace std;

void change(int &a, int *ptr)
{
    a = 80;
    *ptr = 30;
}

int main()
{
    int a = 10;
    int x = 11;

    int &ref = x;
    int *ptr = &a;


  //  change(a, &x);

    cout<<"r = "<<&ref <<"&x = "<<&x<<endl;
  //  cout<<"r = "<<ref <<"ptr = "<<ptr<<endl;

    return 0;
}
