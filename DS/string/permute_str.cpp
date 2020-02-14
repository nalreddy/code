#include<iostream>
#include<string>

using namespace std;

void permuteStr(string str, int l, int r)
{
    if (l == r)
    {
        cout << str << endl;
    }
    else
    {
        for(int i = l; i <= r; i++)
        {
            swap(str[i], str[l]);
            permuteStr(str, l+1, r);
            swap(str[l], str[i]);
        }
    }
}

int main()
{
    string str = "ABCD";
    int n = str.size();
    permuteStr(str, 0, n-1);

    return 0;
}
