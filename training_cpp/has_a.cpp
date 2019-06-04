#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

class Point
{
    int xcord;
    int ycord;
    public:
         Point(int x = 0, int y = 0): xcord(x),ycord(y) { }


         Point& operator+(Point& p)
         {
             xcord = p.xcord;
             ycord = p.ycord;

             return *this;
         }
         void move(int x, int y)
         {
             xcord = x;
             ycord = y;
         }

         void setState(int x, int y)
         {
             xcord = x;
             ycord = y;
         }

         double distance(Point p = 0)
         {
             double d;
             d = sqrt((xcord - p.xcord) * ( xcord - p.xcord) + (ycord - p.ycord) *(ycord - p.ycord));
         }


         void getState(int &x, int &y)
         {
             x = xcord;
             y = ycord;
         }
         friend ostream& operator<<(ostream& out, Point p);
};

ostream& operator<<(ostream& out, Point p)
{
    out << "x cord " << p.xcord << " " << "y cord " << p.ycord << endl;
}

class Circle
{
    int radius;
    Point p;

    public:
    Circle(int x, int y, int r) : radius(r)
    {
        p.setState(x,y);
    }
    Circle(const Point &p1, int r) : radius(r)
    {
        p = p1;
    }


    void show()
    {
        int x, y;
        p.getState(x,y);
        cout << "Circle " <<x << " " << y << " radius " << radius;
    }
};

int main()
{
    Circle c(3,4,6);

    c.show();

    return 0;
}
