#include<iostream>
#include<deque>


using namespace std;

int main()
{
    deque<int> dq;


    dq.push_front(1);
    dq.push_front(2);
    dq.push_back(4);
    dq.push_back(9);
    dq.push_front(8);

    deque<int> :: iterator it;

    for (it = dq.begin(); it != dq.end(); it++) {
         cout << *it << endl;
    }
    return 0;
}
