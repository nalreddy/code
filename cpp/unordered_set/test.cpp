#include <boost/unordered_set.hpp>
#include <iostream>

int main()
{
    typedef boost::unordered_set<size_t> unordered_set;
    unordered_set set;

//    set.reserve(123);
    set.rehash(123);


    for(size_t i = 0; i < 100; i++)
    {
    set.insert(i);
    }
    std::cout << set.size() << '\n';
    std::cout << set.max_size() << '\n';


    std::cout << set.load_factor() << std::endl;
    std::cout << set.bucket_count() << '\n';
    std::cout << set.max_bucket_count() << '\n';


    return 0;
}
