#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(vector<int> v)
{
	cout << endl;

	for(int i = 0; i < v.size(); i++)
		cout << i << " " <<  v[i] << endl;
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

		if (v[mid] == key) {
			cout << " index " << mid  << "  key " << v[mid] << endl; 
			return true;
		}

		if (v[left] <= v[mid])
		{
			if (key >= v[left] && key <= v[mid])
				right = mid - 1;
			else 
				left = mid + 1;
		} else if (key >= v[mid] && key <= v[right]) {
				left = mid + 1;
		} else {
				right = mid - 1;
		}
	}
	return false;
}

int main()
{
	vector<int> v = {3,4,5,6,2,1};
	
	//sort(v.begin(), v.end());
	print(v);
    	
	int k = 6;
	cout << "\n found  %d " <<  k << "  " << binsearch(v, k);

	return 0;
}
