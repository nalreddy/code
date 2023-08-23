// C++ Code to insert a new interval in set of sorted
// intervals and merge overlapping intervals that are
// formed as a result of insertion.
#include <bits/stdc++.h>

using namespace std;

// Define the structure of interval
struct Interval
{
	int s, e;
};

// A subroutine to check if intervals overlap or not.
bool mycomp(Interval a, Interval b) { return a.s < b.s; }

// merge overlapping intervals
void insertNewInterval(vector<Interval>& Intervals, Interval newInterval)
{
	vector<Interval> ans;
	int n = Intervals.size();
	Intervals.push_back(newInterval); //Insert the new interval into Intervals
	sort(Intervals.begin(), Intervals.end(), mycomp);

	int index = 0;
	// Traverse all input Intervals
	for (int i = 1; i <=n; i++) {
		// If this is not first Interval and overlaps
		// with the previous one
		if (Intervals[index].e >= Intervals[i].s) {
			// Merge previous and current Intervals
			Intervals[index].e = max(Intervals[index].e, Intervals[i].e);
		}
		else {
			index++;
			Intervals[index] = Intervals[i];
		}
	}

	for (int i = 0; i <= index; i++)
		cout << Intervals[i].s << ", " << Intervals[i].e << "\n";
}

// Driver code
int main()
{
	vecto<Interval> Intervals;
	Interval newInterval;

	newInterval.s = 1;
	newInterval.e = 2;
	Intervals.push_back(newInterval);
	newInterval.s = 3;
	newInterval.e = 5;
	Intervals.push_back(newInterval);
	newInterval.s = 6;
	newInterval.e = 7;
	Intervals.push_back(newInterval);
	newInterval.s = 8;
	newInterval.e = 10;
	Intervals.push_back(newInterval);
	newInterval.s = 12;
	newInterval.e = 16;
	Intervals.push_back(newInterval);
	newInterval.s = 4;
	newInterval.e = 9;

	insertNewInterval(Intervals, newInterval);

	return 0;
}

// C++ program for above approach
#include <iostream>
#include <stack>
using namespace std;

// Program to merge interval
void mergeInterval2(pair<int, int> arr[],
					int n, pair<int,
							int> newPair)
{
	
	// Create stack of type
	// pair<int, int>
	stack< pair<int, int> > stk;
	
	// Pushing first pair
	stk.push(arr[0]);
	
	// Storing the top element
	pair<int, int> top = stk.top();

	// Checking is newPair.first
	// is less than top.second
	if (newPair.first < top.second)
	{
		
		// Pop the top element
		// as it will merge with the
		// previous range
		stk.pop();
	
		// Re-assigning top.first
		top.first = min(top.first,
						newPair.first);
	
		// Re-assigning top.second
		top.second = max(top.second,
						newPair.second);
	
		// Push the current interval
		stk.push(top);
	}
	else
	{
		
	// Push the new pair as it does
	// not intersect to first pair
	stk.push(newPair);
	}

	// Iterate i from 1 to n - 1
	for (int i = 1; i < n; i++)
	{
		
		// Store the top element of
		// the stack stk
		pair<int, int> top = stk.top();
	
		// Checking is arr[i].first
		// is less than top.second
		if (arr[i].first < top.second)
		{
			
		
			// Pop the top element
			// as it will merge with the
			// previous range
			stk.pop();
		
			// Re-assigning top.first
			top.first = min(top.first,
							arr[i].first);
		
			// Re-assigning top.second
			top.second = max(top.second,
							arr[i].second);
		
			// Push the current interval
			stk.push(top);
		}
		
		else
		{
			
			// Push the new pair as it does
			// not intersect to first pair
			stk.push(arr[i]);
		}
	}
	
	// Storing the final intervals
	stack< pair<int,int> > finalIntervals;

	// Popping the stack elements
	while (stk.empty() != true)
	{
		pair<int, int> ele =
					stk.top();
		stk.pop();
		
		// Push ele in finalIntervals
		finalIntervals.push(ele);
	}

	
	// Displaying the final result
	while (finalIntervals.empty() != true)
	{
		pair<int, int> ele =
					finalIntervals.top();
		finalIntervals.pop();
	
		cout << ele.first << ", "
			<< ele.second << endl;
	}
}

// Driver Code
int main()
{

	pair<int, int> arr2[] = {
		{ 1, 2 }, { 3, 5 }, { 6, 7 },
				{ 8, 10 }, { 12, 16 }
	};
	pair<int, int> newPair{ 4, 9 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	// Function Call
	mergeInterval2(arr2, n2, newPair);

	return 0;
}

// C++ Code to insert a new interval in set of sorted
// intervals and merge overlapping intervals that are
// formed as a result of insertion.
#include <bits/stdc++.h>

using namespace std;

// Define the structure of interval
struct Interval
{
	int start;
	int end;
	Interval()
		: start(0), end(0)
	{
	}
	Interval(int s, int e)
		: start(s), end(e)
	{
	}
};

// A subroutine to check if intervals overlap or not.
bool doesOverlap(Interval a, Interval b)
{
	return (min(a.end, b.end) >= max(a.start, b.start));
}

// Function to insert new interval and
// merge overlapping intervals
vector<Interval> insertNewInterval
(vector<Interval>& Intervals, Interval newInterval)
{
	vector<Interval> ans;
	int n = Intervals.size();

	// If set is empty then simply insert
	// newInterval and return.
	if (n == 0)
	{
		ans.push_back(newInterval);
		return ans;
	}


	// Case 1 and Case 2 (new interval to be
	// inserted at corners)
	if (newInterval.end < Intervals[0].start ||
			newInterval.start > Intervals[n - 1].end)
	{
		if (newInterval.end < Intervals[0].start)
			ans.push_back(newInterval);

		for (int i = 0; i < n; i++)
			ans.push_back(Intervals[i]);

		if (newInterval.start > Intervals[n - 1].end)
			ans.push_back(newInterval);

		return ans;
	}

	// Case 3 (New interval covers all existing)
	if (newInterval.start <= Intervals[0].start &&
		newInterval.end >= Intervals[n - 1].end)
	{
		ans.push_back(newInterval);
		return ans;
	}

	// Case 4 and Case 5
	// These two cases need to check whether
	// intervals overlap or not. For this we
	// can use a subroutine that will perform
	// this function.
	bool overlap = true;
	for (int i = 0; i < n; i++)
	{
		overlap = doesOverlap(Intervals[i], newInterval);
		if (!overlap)
		{
			ans.push_back(Intervals[i]);

			// Case 4 : To check if given interval
			// lies between two intervals.
			if (i < n &&
				newInterval.start > Intervals[i].end &&
				newInterval.end < Intervals[i + 1].start)
				ans.push_back(newInterval);

			continue;
		}

		// Case 5 : Merge Overlapping Intervals.
		// Starting time of new merged interval is
		// minimum of starting time of both
		// overlapping intervals.
		Interval temp;
		temp.start = min(newInterval.start,
						Intervals[i].start);

		// Traverse the set until intervals are
		// overlapping
		while (i < n && overlap)
		{

			// Ending time of new merged interval
			// is maximum of ending time both
			// overlapping intervals.
			temp.end = max(newInterval.end,
						Intervals[i].end);
			if (i == n - 1)
				overlap = false;
			else
				overlap = doesOverlap(Intervals[i + 1],
										newInterval);
			i++;
		}

		i--;
		ans.push_back(temp);
	}

	return ans;
}
