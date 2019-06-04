#include<iostream>

using namespace std;

class foo
{
    public:
        void operator () (int i) { cout << " i = " << i << endl; }
};

