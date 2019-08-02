#include<iostream>

using namespace std;

template<typename T>
class A
{
    public:
        A() { cout << " Ctor called " << endl; }
        A(T x1)
        {
            x = x1; 
            len++;
        }
        ~A() {}
        void print(const A &a);
        size_t get_len() const; 
    private:
        T x;
        size_t len;
};

template<typename T>
size_t A<T> :: get_len() const
{
    return len;
}

template<typename T>
void A<T> :: print(const A &a)
{
    size_t t = a.get_len();
    cout << " a.x " << x << endl;
}

int main()
{
    A <int> a1(2);
    A <int> a2;
    a2.print(a1);
    
}
