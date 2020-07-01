#include<iostream>
#include <boost/scope_exit.hpp>

using namespace std;

int test()
{
    int exit1 = 1;
    int exit2 = 0;

    BOOST_SCOPE_EXIT( (&exit1 ) (&exit2))
    {
        cout << "exit1 " << exit1 << " exit2" << exit2 << endl;
    }
    BOOST_SCOPE_EXIT_END


    if (exit1)
    {
        return exit1;
    }

    if (exit2)
    {
        return exit2;
    }

}
int main()
{
    test();
    return 0;
}
