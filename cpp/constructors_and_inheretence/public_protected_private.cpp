#include<iostream>

using namespace std;

class A
{
    public: 
        A(){ }

        void publicA()
        {
            cout << "public  A's member " <<endl;
        }
    protected:
        void protectedA()
        {
            cout << " protected A' member " << endl;
        }
    private:
        void privateA()
        {
            cout << " private A's member " << endl;
        }
};

class B : protected A
{
    public: 
        B(int m): m(m) { }

       void  printB()
        {
            publicA();
            protectedA();
            cout << " B's member " << m << endl;
        }

    private:
        int m;
};


int main()
{
    B a(4);

    a.printB();

    return 0;
}
