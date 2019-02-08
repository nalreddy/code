#include<iostream>

using namespace std;

class A
{
    public: 
        A()
        {
            cout << " A ctor \n";
        }

    private:
        virtual void show()
        {
            cout << "A show \n";
        }
};

class B : public A
{
    public: 
        B()
        {
            cout << "B ctor \n";
        }

        void show()
        {
            cout << "B show \n";
        }
};

int main()
{
    A *a = NULL;

    B b;

    a = &b;

    a->show();

    return 0;
}
