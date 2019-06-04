#include<iostream>

using namespace std;

class shape
{
    public:
        shape(int x, int y): x(x), y(y) { }
        void getState(int &_x, int &_y) {  _x = x; _y = y; }
        virtual int area() { } 
    private:
        int x;
        int y;
};

class traingle : public shape
{
    public:
        traingle(int h, int b): shape(h,b) { }
        int area() {
             int h, b;
             getState(h,b);
            return h * b; 
        }
};

class rectangle : public shape
{

    public :
        rectangle(int l, int b): shape(l, b) { }
        int area() { int l, b;
            getState(l,b);
             return 2 * l * b; }
};

int main()
{
    traingle t(2,3);
    shape *p = &t; 
    reactangle r(2,3);
    p = &r;

    cout  << " area of traingle " << p->area();
    cout  << " area of reactangle " << p->area();
}
