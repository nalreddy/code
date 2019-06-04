#include <iostream>

void f(int& i) { std::cout << "lvalue ref: " << i << "\n"; }
void f(int&& i) { std::cout << "rvalue ref: " << i << "\n"; }

int main()
{
    int i = 77;
    f(i);    // lvalue ref called
    f(99);   // rvalue ref called

    f(std::move(i));  // rvalue ref called

    return 0;
}
