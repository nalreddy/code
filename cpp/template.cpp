#include<iostream>

using namespace std;

enum sha_type
{
    sha1,
    sha256,
    sha512
};


template <typename T, const enum sha_type x >
class A
{
    public:
        A() 
        { }

        void print_shatype( )
        {
            cout << "sha_type " << x;
        }
};

int main()
{
    sha_type y = sha256;
    const sha_type x = y;
    A<int, x> a;
    a.print_shatype();
    return 0;
}
