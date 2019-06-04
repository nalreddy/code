#include <iostream>
 
class B;
 
class A
{
public:
    void showB(B& );
};
 
class B
{
private:
    int b;
public:
    B()  {  b = 0; }
    void showA(A& a)
    {
        cout << " A = " << A.x <<
    }
    friend void A::showB(B& x); // Friend function
};
 
void A::showB(B &x)
{
    // Since show() is friend of B, it can
    // access private members of B
    std::cout << "B::b = " << x.b;
}
 
int main()
{
    A a;
    B x;
    a.showB(x);
    return 0;
}
