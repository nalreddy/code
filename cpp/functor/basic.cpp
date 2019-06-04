#include<iostream>

using namespace std;

class Adder
{
    public:
        Adder(const int x) : x(x) { }
        int operator()(const int y) const
        {
            return x + y;
        }
    private:
        const int x;
};

int main()
{
    Adder add(20);
    int i = add(3);

    cout << " Added " << i << endl;

    return 0;
}
