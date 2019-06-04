#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

class example
{
    public:
        example(int _x)
        {
            x = _x;
            for(int i = 0 ; i < 5; i++)
            {
                ptr[i] = new int;
                *ptr[i] = i;
                //memcpy(ptr + i, i, 4);
            }
        }

        ~example()
        {
            delete []ptr;
        }
    private:
        int x;
        int* ptr[5];
};

int main()
{
    example *ex = new example(10);

    return 0;
}
