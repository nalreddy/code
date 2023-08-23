#include<iostream>
#include<vector>

using namespace std;
// Assuming all are positives
void find_indexrange(vector<int> arr, int sum)
{
	int cur_sum = 0;
//	int size = sizeof(arr)/sizeof(arr[0]);
	int start = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		cur_sum += arr[i];
		while (cur_sum > sum && start < i)
		{
			cur_sum -= arr[start];
			start++;
		}
		if (cur_sum == sum)
		{
			cout << "found the sum  "<< start  << " and " << i - 1 << endl;
			break;
		}
	}

}

void subarray_sum(vector<int> arr, int sum)
{
	for(int i = 0; i < arr.size(); i++)
	{
		int temp_sum = arr[i];

		if (sum == temp_sum) {
			cout << "found sum at index " << i << " " << arr.size();
			break;
		}
		for (int j = i + 1; j < arr.size(); j++)
		{
			temp_sum += arr[j];
			if (sum == temp_sum)
			{
				cout << "found sum at index "<< i << " " << j << endl;
				break;
			}
		}
	}
}

int main()
{
	vector<int> a = {1, 4, 20, 3, 10, 5};
	int k = 33;

	find_indexrange(a, k);

	subarray_sum(a, k);

	return 0;
}
