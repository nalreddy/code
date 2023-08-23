#include<iostream>
#include<vector>

using namespace std;

void spiral(vector<vector<int> > v) 
{
	int m = v.size(), n = v[0].size();
	int k = 0, l = 0;
	int i = 0;

	cout << " m " << m << " n " << n << endl;
	while ( k < m && l < n ) 
	{
		for (i = l; i < n; i++)
			cout << v[k][i] << " ";
		k++;
		for (i = k; i < m; i++)
			cout << v[i][n -1] << " ";
		n--;
		if ( k < m ) {
			for (i = n-1; i >= l; i--)
				cout << v[m-1][i] << " ";
			m--;
		}

		if ( l < n) {
			for (i = m-1; i >= k; i--)
				cout << v[i][l] << " ";
			l++;
		}
	}
}

int main()
{
    vector<vector<int> > a{ { 1, 2, 3, 4 },
                            { 12, 13, 14, 5 },
                            { 11, 16, 15, 6 },
                            { 10, 9, 8, 7 } };
  
    spiral(a);

    return 0;
}

// C++ Program to print a matrix spirally

#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

void spiralPrint(int m, int n, int a[R][C])
{
	int i, k = 0, l = 0;

	/* k - starting row index
		m - ending row index
		l - starting column index
		n - ending column index
		i - iterator
	*/

	while (k < m && l < n) {
		/* Print the first row from
			the remaining rows */
		for (i = l; i < n; ++i) {
			cout << a[k][i] << " ";
		}
		k++;

		/* Print the last column
		from the remaining columns */
		for (i = k; i < m; ++i) {
			cout << a[i][n - 1] << " ";
		}
		n--;

		/* Print the last row from
				the remaining rows */
		if (k < m) {
			for (i = n - 1; i >= l; --i) {
				cout << a[m - 1][i] << " ";
			}
			m--;
		}

		/* Print the first column from
				the remaining columns */
		if (l < n) {
			for (i = m - 1; i >= k; --i) {
				cout << a[i][l] << " ";
			}
			l++;
		}
	}
}

/* Driver Code */
int main()
{
	int a[R][C] = { { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 } };

	// Function Call
	spiralPrint(R, C, a);
	return 0;
}

// This is code is contributed by rathbhupendra

