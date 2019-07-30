#include<iostream>

using namespace std;

void func(int x, bool t = false, bool y = false);

void func(int x, bool t, bool y)
{
    std::cout << " x  " << x  << " t = " << t  << " y = " << y << std::endl;

}

int main()
{
    func(1);
    func(1,true);
    func(1,true,true);
    return 0;
}
