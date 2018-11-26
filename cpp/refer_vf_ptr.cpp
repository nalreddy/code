#include<iostream>

using namespace std;

#if 0
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
#endif


int main()
{
    string s1("one");
    string s2("two");

    string& rs = s1;

    cout << "s1 " << &s1  << " refer " << &rs;
    return 0;
}
