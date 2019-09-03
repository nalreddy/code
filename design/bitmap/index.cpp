#include<iostream>

using namespace std;

int main()
{
    size_t idx = 8192;
    size_t level = 0;
    size_t blocks = 0;
    size_t div = 1;

    do
    {
        div *= 64;
        size_t quot = idx / div; 
        size_t rem = idx % div;
        blocks =  quot + rem;
        level++;
        std::cout << " quot " << quot << " Rem " << rem << " div " << div << " blocks " << blocks << " level " << level <<std::endl;

    } while (blocks > 0);
    return 0;
}

-------
------
//arry[1] = blockycount
//arry[0] = blockcount * bitsperblock


