#include<iostream>
#include<array>

using namespace std;

int compar(const void* a, const void* b)
{
    int *a1 = (int*) a;
    int *b1 = (int*) b;
    return !(*a1 < *b1);
}

int main()
{
    array<int, 7> ar = {2,1,-2,4,-1,4,6};

    qsort(&ar, ar.size(), sizeof(int), compar);

    for(int i = 0; i < ar.size(); i++)
    {
        std::cout << " i   " << i << " eleme " << ar[i]<< std::endl;
    }

    return 0;
}
