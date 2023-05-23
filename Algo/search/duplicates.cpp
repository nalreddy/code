#include<iostream>
#include<vector>
#include<algorithm>
/*
* sortedArray = { 1, 13, 42, 42, 42, 77, 78 } would print: "42 was found at Indices: 2, 3, 4"
*/
using namespace std;

void print(vector<int> v)
{
	cout << endl;

	for(int i = 0; i < v.size(); i++)
		cout << i << " " <<  v[i] << endl ;
	cout << endl;
}

int rightbinsearch(vector<int> v, int key)
{
	int size = v.size();
	int mid = -1;
	int left = 0;
	int right = size - 1;
	int start = -1;

	while (right >= left)
	{
		mid = (left + right) / 2;
		if (v[mid] == key) {
			start = mid;
			left = mid + 1;
		} else if (v[mid] <= key)
			left = mid + 1;
		else 
		    right = mid - 1;
	}
	return start;
}

int leftbinsearch(vector<int> v, int key)
{
	int size = v.size();
	int mid = -1;
	int left = 0;
	int right = size - 1;
	int start = -1;
	while (right >= left)
	{
		mid = (left + right) / 2;
		if (v[mid] == key) {
			start = mid;
			right = mid - 1;
		}
		else if (v[mid] >= key)
		    right = mid -1;
		else 
			left = mid + 1;
	}
	return start;
}

int main()
{
	vector<int> v = {3,8,10,5,5,5,5,7,20,9,30};
	
	sort(v.begin(), v.end());
	print(v);
	
	int k = 5;
	cout << "\n left found " <<  k << "  " << leftbinsearch(v, k);
	cout << "\n right found " <<  k << "  " << rightbinsearch(v, k);
	cout << endl;

	return 0;
}
