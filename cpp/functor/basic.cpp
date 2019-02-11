#include<iostream>

using namespace std;

class Adder
{
    public:
        Adder(int x) : x(x) { }
        int operator()(int y) const
        {
            return x + y;
        }
    private:
        int x;
};

int main()
{
    Adder add(20);
    int i = add(3);

    cout << " Added " << i << endl;

    return 0;
}
