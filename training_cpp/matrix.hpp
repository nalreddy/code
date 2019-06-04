#include<iostream>

using namespace std;

class matrix
{
    public:

    class row_mat
    {
        friend class matrix;

        public:
        row_mat(matrix& _mat, int _row) : mat(_mat), row(_row) 
        {
        }

        int& operator[](int col)
        {
            return mat.ptr[row][col];
        }

        private:
            matrix& mat;
            int row;
    };
    matrix(int _col, int _row) : col(_col),row(_row) 
    {
        ptr = new int* [row];
        //check for failure
        for (int i = 0; i < row; i++)
            ptr[i] = new int [col];
        //check for failure
    }

    ~matrix()
    {
        for (int i = 0; i < row; i++)
            delete ptr[i];
        delete ptr;
    }

    row_mat operator[](int row)
    {
        return row_mat(*this, row);
    }
#if 0
    void init_matrix()
    {
        for (int i = 0 ; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                cin >> ptr[i][j];
            }
    }
#endif

    int getOrder() const
    {
        return col * row;
    }

    int getCol() const
    {
        return col;
    }

    int getRow() const
    {
        return row;
    }

    void print()
    {
        for (int i = 0 ; i < row; i++)
            for (int j = 0; j < col; j++)
                cout << ptr[i][j]<< " " ;
            cout << endl;
    }

    friend matrix & operator+(const matrix&, const matrix&);
    private:
        int col;
        int row;
        int **ptr;
};

matrix& operator+(const matrix& m1, const matrix& m2)
    {
        if (m1.getOrder() != m2.getOrder())
        { 
            // return error
        }

        int row = m1.getRow();
        int col = m1.getCol();

        matrix *m = new matrix(row, col);

        for (int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                m[i][j] = m1[i][j] + m2[i][j];

        return *m;
    }

