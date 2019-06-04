#include<iostream>
#include<cmath>
#include<string>
#include<sstream>

using namespace std;

void getIndex(size_t offset, size_t inMaxLevels, size_t inLevel)
     {
         size_t index = (offset / (std::pow(48, inMaxLevels - inLevel + 1 )));
         cout << "Offset  " << offset  << "inmaxlevel  " << inMaxLevels << "InLeveL  " << inLevel <<  "Index  : " << index << std::endl;
     }

int main( int argc, const char *argv[])
{
    stringstream off(argv[1]); 
    stringstream level(argv[2]); 


    size_t offset ; 
    size_t inlevel ; 


    off >> offset;
    level >> inlevel;

#if 0
    for ( size_t i = 256; i > 0 && level < 10; )
    {

        for (size_t j = 0; j < i ; j++)
            getIndex(j, 4, level);

        i = i/2;
        level++;
    cout << " i = " << i << " level " << level << endl;
    }

#endif
    getIndex( offset, 3, inlevel);
    return 0;
}
