#include<iostream>

using namespace std;

static const int x = 10;
template <const int z = x>
class A
{
    public:
        A()
        {
            size = z;
        }
        int sz();
    private:
        uint8_t a[z];
        int size;
};

template<const int z>
int A<z>::sz()
{
    return size;
}

int main()
{
    A<> *a = new A<>();
    cout << " size "  << a->sz();
    return 0;
}
