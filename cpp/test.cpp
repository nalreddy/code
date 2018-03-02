#include <iostream>
using namespace std;

struct A
{
    int a;
    char c;
};

void print() 
{
 
    struct A x;
    
    x.a = 4;
    x.c = 'a';

    struct A *ptr = &x;

    cout <<"hello world ptr "<<ptr <<endl;
  
    cout<<"print function\n";
}

int main() {
   print();

    for ( int i = 0; i < 10; i++) 
    {
        cout<<" i = "<<i<<endl;
    }

    return 0;
}
