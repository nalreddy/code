#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum
// water that can be stored
int maxWater(int arr[], int n)
{
	// To store the maximum water
	// that can be stored
	int res = 0;

	// For every element of the array
	for (int i = 1; i < n - 1; i++) {

		// Find the maximum element on its left
		int left = arr[i];
		for (int j = 0; j < i; j++)
			left = max(left, arr[j]);

		// Find the maximum element on its right
		int right = arr[i];
		for (int j = i + 1; j < n; j++)
			right = max(right, arr[j]);

		// Update the maximum water
		res = res + (min(left, right) - arr[i]);
	}

	return res;
}

// Driver code
int main()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << maxWater(arr, n);

	return 0;
}

// C++ program to find maximum amount of water that can
// be trapped within given set of bars.
#include <bits/stdc++.h>
using namespace std;

int findWater(int arr[], int n)
{
	// left[i] contains height of tallest bar to the
	// left of i'th bar including itself
	int left[n];

	// Right [i] contains height of tallest bar to
	// the right of ith bar including itself
	int right[n];

	// Initialize result
	int water = 0;

	// Fill left array
	left[0] = arr[0];
	for (int i = 1; i < n; i++)
		left[i] = max(left[i - 1], arr[i]);

	// Fill right array
	right[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
		right[i] = max(right[i + 1], arr[i]);

	// Calculate the accumulated water element by element
	// consider the amount of water on i'th bar, the
	// amount of water accumulated on this particular
	// bar will be equal to min(left[i], right[i]) - arr[i]
	// .
	for (int i = 1; i < n - 1; i++) {
		int var = min(left[i - 1], right[i + 1]);
		if (var > arr[i]) {
			water += var - arr[i];
		}
	}

	return water;
}

// Driver program
int main()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findWater(arr, n);
	return 0;
}

nclude <bits/stdc++.h>
using namespace std;

// Function to return the maximum
// water that can be stored
int maxWater(int height[], int n)
{

	// Stores the indices of the bars
	stack<int> st;

	// Stores the final result
	int ans = 0;

	// Loop through the each bar
	for (int i = 0; i < n; i++) {

		// Remove bars from the stack
		// until the condition holds
		while ((!st.empty())
			&& (height[st.top()] < height[i])) {

			// Store the height of the top
			// and pop it.
			int pop_height = height[st.top()];
			st.pop();

			// If the stack does not have any
			// bars or the popped bar
			// has no left boundary
			if (st.empty())
				break;

			// Get the distance between the
			// left and right boundary of
			// popped bar
			int distance = i - st.top() - 1;

			// Calculate the min. height
			int min_height
				= min(height[st.top()], height[i])
				- pop_height;

			ans += distance * min_height;
		}

		// If the stack is either empty or
		// height of the current bar is less than
		// or equal to the top bar of stack
		st.push(i);
	}
	return ans;
}

// Driver code
int main()
{

	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << maxWater(arr, n);

	return 0;
}

// The code is contributed by Soumitri Chattopadhyay
nclude <bits/stdc++.h>
using namespace std;

int trappedWater(vector<int>& arr)
{
	int num_blocks = 0;
	int n = 0;
	int max_height = INT_MIN;

	// Find total blocks, max height and length of array
	for (auto height : arr) {
		num_blocks += height;
		n += 1;
		max_height = max(max_height, height);
	}

	// Total water, left pointer and right pointer
	// initialized to 0 and n - 1
	int total = 0;
	int left = 0;
	int right = n - 1;

	for (int i = 1; i <= max_height; i++) {

		// Find leftmost point greater than current row (i)
		while (arr[left] < i)
			left += 1;

		// Find rightmost point greater than current row (i)
		while (arr[right] < i)
			right -= 1;

		// water in this row = right - left + 1
		total += (right - left + 1);
	}

	total -= num_blocks;
	return total;
}

// Driver code
int main()
{
	vector<int> arr
		= { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

	// Function call
	cout << trappedWater(arr) << endl;
	return 0;
}

// This code is contributed by shinjanpatra
nclude <bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n)
{
	// Indices to traverse the array
	int left = 0;
	int right = n-1;

	// To store Left max and right max
	// for two pointers left and right
	int l_max = 0;
	int r_max = 0;

	// To store the total amount
	// of rain water trapped
	int result = 0;
	while (left <= right)
	{

	// We need check for minimum of left
	// and right max for each element
	if(r_max <= l_max)
	{

		// Add the difference between
		// current value and right max at index r
		result += max(0, r_max-arr[right]);

		// Update right max
		r_max = max(r_max, arr[right]);

		// Update right pointer
		right -= 1;
	}
	else
	{

		// Add the difference between
		// current value and left max at index l
		result += max(0, l_max-arr[left]);

		// Update left max
		l_max = max(l_max, arr[left]);

		// Update left pointer
		left += 1;
	}
	}
	return result;
}

// Driver code
int main() {
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int N = sizeof(arr)/sizeof(arr[0]);
	cout << maxWater(arr, N) << endl;
	return 0;
}

// This code is contributed by avanitrachhadiya2155
nclude <bits/stdc++.h>
using namespace std;

// Function to return the maximum
// water that can be stored
int maxWater(int arr[], int n)
{
	int size = n - 1;

	// Let the first element be stored as
	// previous, we shall loop from index 1
	int prev = arr[0];

	// To store previous wall's index
	int prev_index = 0;
	int water = 0;

	// To store the water until a larger wall
	// is found, if there are no larger walls
	// then delete temp value from water
	int temp = 0;
	for (int i = 1; i <= size; i++) {

		// If the current wall is taller than
		// the previous wall then make current
		// wall as the previous wall and its
		// index as previous wall's index
		// for the subsequent loops
		if (arr[i] >= prev) {
			prev = arr[i];
			prev_index = i;

			// Because larger or same
			// height wall is found
			temp = 0;
		}
		else {

			// Since current wall is shorter than
			// the previous, we subtract previous
			// wall's height from the current wall's
			// height and add it to the water
			water += prev - arr[i];

			// Store the same value in temp as well
			// If we dont find any larger wall then
			// we will subtract temp from water
			temp += prev - arr[i];
		}
	}

	// If the last wall was larger than or equal
	// to the previous wall then prev_index would
	// be equal to size of the array (last element)
	// If we didn't find a wall greater than or equal
	// to the previous wall from the left then
	// prev_index must be less than the index
	// of the last element
	if (prev_index < size) {

		// Temp would've stored the water collected
		// from previous largest wall till the end
		// of array if no larger wall was found then
		// it has excess water and remove that
		// from water variable
		water -= temp;

		// We start from the end of the array,
		// so previous should be assigned to
		// the last element
		prev = arr[size];

		// Loop from the end of array up to the
		// previous index which would contain
		// the largest wall from the left
		for (int i = size; i >= prev_index; i--) {

			// Right end wall will be definitely
			// smaller than the 'previous index' wall
			if (arr[i] >= prev) {
				prev = arr[i];
			}
			else {
				water += prev - arr[i];
			}
		}
	}

	// Return the maximum water
	return water;
}

// Driver Code
int main()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int N = sizeof(arr) / sizeof(arr[0]);

	cout << maxWater(arr, N);
	return 0;
}

// This code is contributed by Debidutta Rath

