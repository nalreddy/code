#include<iostream>
#include<vector>

using namespace std;

void min_platform(vector<int>& arr, vector<int>& dep)
{
	int min_count = 1;
	int result = 1;
	int size = arr.size();

	for (int i = 0; i < size; i++)
	{
		min_count = 1;
		for(int j = 0; j < size; j++)
		{
			if (i != j && arr[i] >= arr[j] && dep[j] >= arr[i]) 
			{
				min_count++;
			}
		}
		result = result > min_count ? result : min_count;
	}

	cout << "platform needed " << result<< endl;
}

int main()
{
	vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
	vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

	min_platform(arr, dep);

	return 0;
}
#if 0
// C++ program to implement the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of platforms
// required
int findPlatform(int arr[], int dep[], int n)
{
	// plat_needed indicates number of platforms
	// needed at a time
	int plat_needed = 1, result = 1;

	// Run a nested for-loop to find the overlap
	for (int i = 0; i < n; i++) {

		// Initially one platform is needed
		plat_needed = 1;
		for (int j = 0; j < n; j++) {
			if (i != j)
				// Increment plat_needed when there is an
				// overlap
				if (arr[i] >= arr[j] && dep[j] >= arr[i])
					plat_needed++;
		}

		// Update the result
		result = max(plat_needed, result);
	}
	return result;
}

// Driver Code
int main()
{

	// Train 1 => Arrival : 01:00, Departure : 09:00
	// Train 2 => Arrival : 03:00, Departure : 04:00
	// Train 3 => Arrival : 05:00, Departure : 06:00
	int arr[] = { 100, 300, 500 };
	int dep[] = { 900, 400, 600 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findPlatform(arr, dep, n);
	return 0;
}

// Code contributed by farzams101

// Program to find minimum number of platforms
// required on a railway station
#include <algorithm>
#include <iostream>

using namespace std;

// Returns minimum number of platforms required
int findPlatform(int arr[], int dep[], int n)
{
	// Sort arrival and departure arrays
	sort(arr, arr + n);
	sort(dep, dep + n);

	// plat_needed indicates number of platforms
	// needed at a time
	int plat_needed = 1, result = 1;
	int i = 1, j = 0;

	// Similar to merge in merge sort to process
	// all events in sorted order
	while (i < n && j < n) {
		// If next event in sorted order is arrival,
		// increment count of platforms needed
		if (arr[i] <= dep[j]) {
			plat_needed++;
			i++;
		}

		// Else decrement count of platforms needed
		else if (arr[i] > dep[j]) {
			plat_needed--;
			j++;
		}

		// Update result if needed
		if (plat_needed > result)
			result = plat_needed;
	}

	return result;
}

// Driver code
int main()
{
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findPlatform(arr, dep, n);
	return 0;
}
// C++ program to implement the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number
// of platforms required
int findPlatform(int arr[], int dep[], int n)
{
	// Store the arrival and departure time
	vector<pair<int, int> > arr2(n);

	for (int i = 0; i < n; i++) {
		arr2[i] = { arr[i], dep[i] };
	}

	// Sort arr2 based on arrival time
	sort(arr2.begin(), arr2.end());

	priority_queue<int, vector<int>, greater<int> > p;
	int count = 1;
	p.push(arr2[0].second);

	for (int i = 1; i < n; i++) {

		// Check if arrival time of current train
		// is less than or equals to departure time
		// of previous train
		if (p.top() >= arr2[i].first) {
			count++;
		}
		else {
			p.pop();
		}
		p.push(arr2[i].second);
	}

	// Return the number of trains required
	return count;
}

// Driver Code
int main()
{
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findPlatform(arr, dep, n);
	return 0;
}

#endif
