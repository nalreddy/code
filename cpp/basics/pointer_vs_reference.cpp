#include <iostream>
#include <stdio.h>

using namespace std;


int main() {
    int x = 5;
    int y = 4;

    int *p = &x;
    
    int &r = x;

    printf("hello world *p = %p *r %p &x = %p \n", &p,&r, &x);
    return 0;
}
