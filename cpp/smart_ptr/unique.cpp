#include<iostream>
#include<memory>

using namespace std;

class A
{
    public:
        void show()
        {
            cout << "A show \n";
        }
};

int main()
{
//    A *a = new A();
    unique_ptr<A> p1(new A);

    p1->show();

    cout << " count " << p1.get() << endl;

    unique_ptr<A> p2 = move(p1);

    cout << " count " << p1.get() << endl;
    cout << " count " << p2.get() << endl;

    cout << " address " << a << endl;
    p2->show();
    p1->show();

    return 0;
}
