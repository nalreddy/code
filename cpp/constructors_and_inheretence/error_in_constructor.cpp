#include<exception>
#include<iostream>

using namespace std;

class A
{
    public:
        A()
        {
            std::cout << "before ctor " << std::endl;
            throw std::runtime_error("failed to construct");
            std::cout << "after ctor " << std::endl;
        }
        ~A()
        {
            std::cout << " dtor " << std::endl;
        }
};

int main()
{
    {
        try
        {
            A a;
        } catch (const std::exception& e)
        {
            std::cout << "got you " << std::endl;
        }
    }
    return 0;
}
