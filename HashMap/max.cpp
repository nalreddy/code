#include <iostream>
//#include <unordered_map>
#include <boost/unordered_map.hpp>

using namespace std;

int main(){

    boost::unordered_map<size_t, size_t> map;
    map[21] = 12;

    cout << map.size() << endl << map.max_size() << endl;

    return 0;
}
