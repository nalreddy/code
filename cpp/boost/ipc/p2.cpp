#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

#include <chrono>
#include <thread>

using namespace boost::interprocess;

int main()
{
    shared_memory_object shdmem{open_only, "Boost", read_only};
//    shdmem.truncate(1024);
    mapped_region region{shdmem, read_only};
    int *i1 = static_cast<int*>(region.get_address());
//    *i1 = 99;

    std::cout << *i1 << '\n';
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);

    return 0;
}
