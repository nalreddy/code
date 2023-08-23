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

bool pairbinsearch(vector<int> v, int key)
{
	int size = v.size();
	int mid = -1;
	int left = 0;
	int right = size - 1;

	for (int i = 0; i < size - 1; i++)
	{
		if (v[i] > v[i + 1])  
	}
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
	vector<int> v = {4,5,6,7,1,2,3};
	
	print(v);
	
	int k = 9;
	cout << " find pair  " << pairbinsearch(v, k);

	return 0;
}
