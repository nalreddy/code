#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(vector<int> v)
{
	cout << endl;

	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " " ;
	cout << endl;
}

bool binsearch(vector<int> v, int key)
{
	int size = v.size();
	int mid = -1;
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (v[mid] == key) 
			return true;
		else if (v[mid] < key)
			left = mid + 1;
		else 
		    right = mid - 1;
	}
	return false;
}

int main()
{
	vector<int> v = {3,8,10,5,7,20,9,30};
	
	sort(v.begin(), v.end());
	print(v);
	
	int k = 9;
	cout << "\n found  %d " <<  k << "  " << binsearch(v, k);
	k = 8;
	cout << "\n found  %d " <<  k << "  " << binsearch(v, k);
	k = 31;
	cout << "\n found  %d " <<  k << "  " << binsearch(v, k);

	return 0;
}
