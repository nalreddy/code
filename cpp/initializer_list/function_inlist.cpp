#include<iostream>

using namespace std;

class A
{
    public:
        A(int _x, int _y, int _z) : x(_x), z(_z) { setY(_y); }
        void setY(int _y)
        {
            y =_y;
        }
    private: 
        int x;
        int y;
        int z;
};
int main()
{
    A a(1,2,3);

    return 0;
}
