#include<iostream>

using namespace std;

void show(int x)
{
    cout << " const \n";
}

void show(const int x)
{
    cout << " const \n";
}
#if 0
inline show()
{
    cout << " hi \n";
}

void show()
{
    cout << " hi \n";
}

int show()
{
    return 1;
}
static void show(int x)
{
    cout << " empty param \n";
}

void show(int x = 2)
{
    cout << " empty param \n";
}
void show(int a)
{
    cout << " one param \n";
}

void show(char a)
{
    cout << " char one param \n";
}
void show(char a, char b)
{
    cout << " char two  param \n";
}

#endif
int main()
{
    show(1);

    return 0;
}
