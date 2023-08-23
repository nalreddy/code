#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

void find_pair(vector<int> v, int sum)
{
	int l, r;

	sort(v.begin(), v.end());

	while(l < r) {
		if (v[l] + v[r] == sum) {
			cout << "Found them " << v[l] << " , " << v[r] << endl;
			return;
		}
		else if (v[l] + v[r] < sum)
			l++;
		else 
			r--;
	}
	cout << "could n't find any pair  " << endl;
	return;
}

bool search(vector<int> v, int start, int end, int key)
{
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (v[mid] == key) {
			cout << "found them "<< endl;
			return true;
		}
		if (key > v[mid]) start = mid + 1;
		else 
		   end = mid - 1;
	}
	return false;
}

void find_pair_binarysearch(vector<int> v, int sum)
{
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		int key = sum - v[i];
		if (search(v, i + 1, v.size() -1, key)) return;
	}

	return;
}

void printPairs(vector<int> arr, int arr_size, int sum)
{
	unordered_set<int> s;
	for (int i = 0; i < arr_size; i++) {
		int temp = sum - arr[i];

		if (s.find(temp) != s.end()) {
			cout << "Yes" << endl;
			return;
		}
		s.insert(arr[i]);
	}
	cout << "No" << endl;
}

int main()
{
	vector<int> v = { 1, 4, 45, 6, 10, -8};
//	find_pair(v, 16);
//	find_pair_binarysearch(v, 16);
	printPairs(v, v.size(), 16);
	return 0;
}
