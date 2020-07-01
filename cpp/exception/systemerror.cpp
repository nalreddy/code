#include <iostream>
#include <exception>
#include <stdexcept>
#include <assert.h>
//#include <system_error>

using namespace std;

void func()
{
 //   int len = -1;
//    assert(len >= 0);
    int *p = NULL;
    printf(" val %d", *p);
}
int main()
{
#if 0
//    test();
    try {
        A a;
    } catch (std::exception const& e) {
        std::cout<<e.what() << endl;
    }
//    throw std::system_error(errno, std::generic_category(), "Client failed to connect");
    std:: cout<< "after catch " << endl;
#endif
    try
    {
        func();
    }

     catch (std::exception const& e) 
//    catch (std::system_error& ex)
    {
        //    std::cout << "Error: " << error.code() << " - " << error.what() << '\n';
//        std::cout << ex.code() << '\n';
  //      std::cout << ex.code().message() << '\n';
        std::cout << e.what() << '\n';
    }

    return 0;
}

