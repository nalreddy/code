#include<string>
#include<iostream>
#include <boost/atomic.hpp>

using namespace std;

struct target
{
    string name;
    int lun;
};

struct target  test()
{
    struct target tgt;

    tgt.name = "node0";
    tgt.lun = 2;
    return tgt;
}
void f(std::string &name)
{
    boost::atomic<size_t>  mBdevCounter(23);
    mBdevCounter++;
    std::string nm = "Malloc" + to_string(mBdevCounter);
    name = nm;

    struct target tgt = test();

}
int main()
{
    std::string name;
    f(name);
    cout << " name " << name  << endl;
    return 0;
}
