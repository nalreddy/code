#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

#include <chrono>
#include <thread>

using namespace boost::interprocess;

int main()
{
    shared_memory_object shdmem{open_or_create, "Boost", read_write};
    shdmem.truncate(1024);
    mapped_region region{shdmem, read_write};
    int *i1 = static_cast<int*>(region.get_address());
    *i1 = 123;

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(10s);

    std::cout << *i1 << '\n';
}
