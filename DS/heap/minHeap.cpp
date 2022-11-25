#include<iostream>

using namespace std;


class MinHeap {
	private:
		int capacity;
		int size;
		int *ar;

		bool full() {
			if (size == capacity) 
				return true;
			else
				return false;
		}
			     
	public :
		MinHeap(int _capacity): capacity(_capacity) {
			size = 0;
			ar = new int(capacity);
		}

		void print() {
			if (!size) {
				cout << "empty" << endl;
				return;
			}
			for (int i = 0; i < size; i++) {
				cout << ar[i];
			}
			cout << endl;
		}
		// should return errors
		void insert(int key) {
			if (full()) {
				cout << "heap full" << endl;
			}
			size++;
			int i = size - 1;
			ar[i] = key;

		}

};

int main() {
	MinHeap *m = new MinHeap(10);
	m->print();
	return 0;
}
