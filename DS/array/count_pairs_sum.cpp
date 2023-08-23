#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

void find_pairs(vector<int> v, int sum)
{
	unordered_map<int, int> mp;
	int count = 0;

	for (int i = 0; i < v.size(); i++)
	{
		int temp = sum - v[i]; 
		if (mp.find(temp) != mp.end())
				count += mp[temp];
		mp[v[i]]++;
	}
	cout << "cout  " << count << endl;
}

int main()
{
	vector<int> v = { 1, 5, 7, -1, 5 };
	find_pairs(v, 6);

	return 0;
}
