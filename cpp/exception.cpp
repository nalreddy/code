#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class A
{
    public :
        
        ~A() {
            int x = 10, y = 0;

            std::cout<< "destructor called "<< endl;
            if( y == 0) {
                throw std::overflow_error("Divede by zero exception");
            }
//            y = x/0;
        }
};

void test() throw()
{
    cout << "not thrwoing " << endl;
    try {
        throw " test exception";
    } catch (...) {
        cout << "caught exception but do nothing" << endl;
    }
}
#if 0

struct MyException : public exception {
   const char * what () const throw () {
      return "C++ Exception";
   }
};
 
int main() {
   try {
      throw MyException();
   } catch(MyException& e) {
      std::cout << "MyException caught" << std::endl;
      std::cout << e.what() << std::endl;
   } catch(std::exception& e) {
      //Other errors
   }
}
#endif

int main()
{
//    test();
    try {
        A a;
    } catch (std::exception const& e) {
        std::cout<<e.what() << endl;
    }
    std:: cout<< "after catch " << endl;
    return 0;
}

