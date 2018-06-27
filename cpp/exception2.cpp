#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

void test() 
{
        throw " test exception";
        cout << "after throw " << endl;
}

void func()
{

    test();
    cout << " after test calling " << endl;
}
int main()
{
    func();
#if 0
//    test();
    try {
        A a;
    } catch (std::exception const& e) {
        std::cout<<e.what() << endl;
    }
    std:: cout<< "after catch " << endl;
#endif
    return 0;
}


