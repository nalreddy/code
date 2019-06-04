#include<iostream>

using namespace std;

class CMatrix {
    public:
        class CRow {
            friend class CMatrix;
            public:
            int& operator[](int col)
            {
                cout << "called Crow[] " << endl;
                return parent.arr[row][col];
            }
            private:
            CRow(CMatrix &parent_, int row_) : 
                parent(parent_),
                row(row_)
            {
                cout << "Crow " << endl;
            }

            CMatrix& parent;
            int row;
        };

        CRow operator[](int row)
        {
            cout << "called mat [] " << endl;
            return CRow(*this, row);
        }

        CMatrix(int _rows, int _cols)
        {
            rows = _rows;
            cols = _cols;

            arr = new int* [rows];
            for (int i = 0; i < rows; i++)
                arr[i] = new int [cols];
        }

    private:
        int rows, cols;
        int **arr;
};

int main()
{
    CMatrix mat(4,4);

    cout << " enter value " << endl;
    cin >> mat[0][0];
    cout << mat[0][0];
    return 0;
}
