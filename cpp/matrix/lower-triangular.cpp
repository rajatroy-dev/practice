#include <iostream>

using namespace std;

// A square matrix is called lower triangular if all the entries above the main diagonal are zero.
class LowerTriangular
{
    int *array;
    int rows_columns;

    int get_index(int m, int n)
    {
        // Row major
        // return (m * (m - 1)) / 2 + n - 1;

        // Column major
        return this->rows_columns * (n - 1) - (n - 1) * (n - 2) / 2 + m - n;
    }

public:
    LowerTriangular(int rows_columns)
    {
        int array_size = (rows_columns * (rows_columns + 1)) / 2;
        this->array = new int[array_size];
        this->rows_columns = rows_columns;
    }

    ~LowerTriangular()
    {
        delete[] this->array;
    }

    void set(int m, int n, int x)
    {
        if (n <= m)
            this->array[this->get_index(m, n)] = x;
    }

    int get(int m, int n)
    {
        if (n <= m)
            return this->array[this->get_index(m, n)];

        return 0;
    }

    void display()
    {
        for (int m = 1; m <= this->rows_columns; m++)
        {
            for (int n = 1; n <= this->rows_columns; n++)
            {
                if (n <= m)
                {
                    cout << this->array[this->get_index(m, n)] << " ";
                }
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main()
{
    LowerTriangular *lower_triangular = new LowerTriangular(3);

    lower_triangular->set(1, 1, 1);
    lower_triangular->set(1, 2, 2);
    lower_triangular->set(1, 3, 3);
    lower_triangular->set(2, 1, 1);
    lower_triangular->set(2, 2, 2);
    lower_triangular->set(2, 3, 3);
    lower_triangular->set(3, 1, 1);
    lower_triangular->set(3, 2, 2);
    lower_triangular->set(3, 3, 3);

    cout << "(1, 1): " << lower_triangular->get(1, 1) << endl;
    cout << "(1, 2): " << lower_triangular->get(1, 2) << endl;
    cout << "(1, 3): " << lower_triangular->get(1, 3) << endl;
    cout << "(2, 1): " << lower_triangular->get(2, 1) << endl;
    cout << "(2, 2): " << lower_triangular->get(2, 2) << endl;
    cout << "(2, 3): " << lower_triangular->get(2, 3) << endl;
    cout << "(3, 1): " << lower_triangular->get(3, 1) << endl;
    cout << "(3, 2): " << lower_triangular->get(3, 2) << endl;
    cout << "(3, 3): " << lower_triangular->get(3, 3) << endl;

    lower_triangular->display();

    return 0;
}