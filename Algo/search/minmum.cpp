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

int minbinsearch(vector<int> v)
{
	int size = v.size();
	int mid = -1;
	int left = 0;
	int right = size - 1;

	if (v[left] <= v[right]) return v[left];
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (v[mid] < v[mid-1]) return v[mid];
		else if (v[mid] > v[right]) 
			left = mid + 1;
		else 
		    right = mid - 1;
	}
	return -1;
}

int main()
{
	vector<int> v = {4,5,6,7,1,2,3};

	sort(v.begin(), v.end());
	print(v);
	
	cout << "\n found  " << minbinsearch(v);
	cout << endl;

	return 0;
}
