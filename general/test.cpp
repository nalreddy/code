#include<unordered_set>
#include<iostream>

using namespace std;
#define COUNT 100
#define SUB 4 
struct element
{
    uint8_t e [21];
};

#if 0
struct bucket
{
    struct element  num[SUB];
};

int main()
{
    //std::cout << " element size " << sizeof(struct element) << endl;
    std::cout << " element size " << sizeof(struct bucket) << endl;
    return 0;
}
#endif

int main()
{
    std::cout << "size " << sizeof(std::unordered_set<double> ) << endl;
    return 0;
}
