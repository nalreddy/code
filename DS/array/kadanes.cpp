#include<iostream>
#include<vector>

using namespace std;


void largest_sum_continuos_array(vector<int> array)
{
	int cur_sum = 0;
	int largest_sum = 0;
	int start = 0, end = 0;
	int temp = 0;

	for (int i = 0; i < array.size(); i++)
	{
		cur_sum += array[i];
		if (cur_sum < 0) 
		{
			cur_sum = 0;
			temp = i + 1;
		}

		if (cur_sum > largest_sum)
		{
			largest_sum = cur_sum;
			start = temp;
			end = i;
		}
	}
	cout << "largest sum " << largest_sum << " start " << start << " end " << end << endl;
}

int main()
{
	vector<int> array = { -2, -3, 4, -1, -2, 1, 5};
	largest_sum_continuos_array(array);

	return 0;
}
