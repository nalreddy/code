#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MinHeap 
{
		int *arr;
		int size;
		int capacity;

		public :
		MinHeap(vector<int>& a, int s)
		{
				int i = 0;
				arr = new int(s);
				for (int i = 0; i < s; i++)
				{
						arr[i] = a[i]; 
				}
				size = s; 
				print();
				i = (size - 1) / 2;

				while (i >= 0)
				{
						heapify(i);
						i--;
				}
		}
		void print();
		void heapify(int i);
		int parent(int i) { return (i -1) /2; } 
		int left(int i) { return 2 * i + 1; } 
		int right(int i) { return 2 * i + 2; } 
		void swap(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }
		int  extractMin();
};

void MinHeap :: print()
{
		for (int i = 0; i < size; i++)
		{
				cout << arr[i] << " ";
		}
		cout << endl;
}

void MinHeap :: heapify(int i)
{
		int l = left(i);  
		int r = right(i);  
		int smallest = i;

		if ( l < size && arr[smallest] > arr[l])
				smallest = l;
		if ( r < size && arr[smallest] > arr[r])
				smallest = r;

		if (smallest != i)
		{
				swap(&arr[i], &arr[smallest]);
				heapify(smallest);
		}
}

int MinHeap :: extractMin()
{
		int ret = arr[0];

		if (size > 1)
		{
				arr[0] = arr[size-1];
				heapify(0);
		}
		size--;
		return ret;
}

#if 0
void kthsmallest(vector<int>&v, int k)
{
        sort(v.begin(), v.end());
        cout << v[k-1] << endl;
}
#else
int kthsmallest(vector<int> &v, int k)
{
    int ret = 0;
    MinHeap h(v, v.size());
    for (int i = 0; i < k; i++)
    {
        ret = h.extractMin();

    }
    return ret;
}

#endif

int main()
{
		vector<int> v = {4,7,2,8,1,9};

//		MinHeap h(v, v.size());
//		h.print();

		cout << kthsmallest(v, 2) << endl;
		return 0;
}
