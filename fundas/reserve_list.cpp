#include<iostream>

using namespace std;

const int MaxReservableBucketCount = 5 ;
const int ReservableBucketPctRange = 100 / MaxReservableBucketCount;
     
int
Index(int reserved)
{
    int capacity = 100;

    const int reservablePct (100 - (reserved*100)/capacity);
    if (reservablePct == 0) {
        return 0;
    }

    int index;
    const int rem (reservablePct % ReservableBucketPctRange);
    if (rem == 0)
    {
        index = reservablePct/ReservableBucketPctRange - 1;
    }
    else
    {
        index = (reservablePct + ReservableBucketPctRange - rem)/ReservableBucketPctRange - 1;
    }

    cout << " Reserved  " << reserved << " capacity  " << capacity  << " index " << index << endl;
    return index;
}

int main()
{
    int id[]= {0, 10, 20, 30,40,50,60,70,80,90,100 };

    for (int i = 0; i < 11; i++)
        Index(id[i]);

    return 0;
}
