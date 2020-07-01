#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include <iomanip>

using namespace std;

int main()
{
    uint64_t ino = 1152921532604227587;
   // uint32_t igen = 3893539803;
    uint32_t igen = 3893533;
    uint32_t fsid = 6835298;
    std::stringstream stream;
    stream << std::hex << fsid << ino << igen;

    int len =  stream.str().length();

    cout << " len " << len;
    cout << endl;
    stream << std::setw((32 - len) /2)  << std::setfill('0') << stream.str();
    std::string result( stream.str() );

    cout << " bdevname  " << result << "len : " << result.length();
    cout << endl;
    cout << " C bdev  " << result.c_str() << "len : " << strlen(result.c_str());
    cout << endl;
    return 0;

}
