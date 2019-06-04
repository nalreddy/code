#include "node.hpp"

using namespace std;
int main() {
    Cache cache(2);  // cache capacity 2
    cache.put(2,2);
    cache.put(1,1);

    cout << cache.get(2) << endl;
    cout << cache.get(1) << endl;

    cache.put(1,5);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    cache.put(8,8);
    cout << cache.get(1) << endl;
    cout << cache.get(8) << endl;
}
