#include <iostream>

using namespace std;

class A
{
      public:
            virtual void show()
                  {
                          cout << " A show \n"; 
                            }
};

class B : public A
{
      private:
            void show()
                  {
                          cout << "B show \n";
                            }
};
int main() {
      A *a = new B();

        a->show();

}
