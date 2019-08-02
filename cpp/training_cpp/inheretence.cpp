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

         void move(int x, int y)
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

class Circle : public Point
{
    int radius;
    public:
    Circle(int x, int y, int r) : Point(x,y), radius(r) { }

    void show()
    {
        int x, y;
        getState(x,y);
        cout << "Circle " <<x << " " << y < " radius " << radius;
    }
};

int main()
{
    Point p(3,4);

    cout << p;
    return 0;
}
