#include<iostream>
#include<string>

using namespace std;

class A
{
    public:
        A(int _x, char _y, string _str)
        {
            x =_x;
            y = _y;
            str = _str;
        }
        ~A() { }

        friend std::ostream& operator <<(std::ostream& s, const A& a)
        {
            s << "x = " << a.x
                << " y = " << a.y
                << " str = " << a.str << std::endl;
            return s;
        }
    private:
        char y;
        int x;
        string str;
};

int main()
{
    A a(2, 'x', "abc");

    std::cout << a;
    return 0;
}
