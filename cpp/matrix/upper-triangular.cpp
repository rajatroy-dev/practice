#include <iostream>

using namespace std;

// A square matrix is called upper triangular if all the entries below the main diagonal are zero.
class UpperTriangular
{
    int *array;
    int rows_columns;

    int get_index(int m, int n)
    {
        // Row major
        // return this->rows_columns * (m - 1) - (m - 1) * (m - 2) / 2 + n - m;

        // Column major
        return (n * (n - 1)) / 2 + m - 1;
    }

public:
    UpperTriangular(int rows_columns)
    {
        int array_size = (rows_columns * (rows_columns + 1)) / 2;
        this->array = new int[array_size];
        this->rows_columns = rows_columns;
    }

    ~UpperTriangular()
    {
        delete[] this->array;
    }

    void set(int m, int n, int x)
    {
        if (n >= m)
            this->array[this->get_index(m, n)] = x;
    }

    int get(int m, int n)
    {
        if (n >= m)
            return this->array[this->get_index(m, n)];

        return 0;
    }

    void display()
    {
        for (int m = 1; m <= this->rows_columns; m++)
        {
            for (int n = 1; n <= this->rows_columns; n++)
            {
                cout << this->get(m, n) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    UpperTriangular *upper_triangular = new UpperTriangular(3);

    upper_triangular->set(1, 1, 1);
    upper_triangular->set(1, 2, 2);
    upper_triangular->set(1, 3, 3);
    upper_triangular->set(2, 1, 1);
    upper_triangular->set(2, 2, 2);
    upper_triangular->set(2, 3, 3);
    upper_triangular->set(3, 1, 1);
    upper_triangular->set(3, 2, 2);
    upper_triangular->set(3, 3, 3);

    cout << "(1, 1): " << upper_triangular->get(1, 1) << endl;
    cout << "(1, 2): " << upper_triangular->get(1, 2) << endl;
    cout << "(1, 3): " << upper_triangular->get(1, 3) << endl;
    cout << "(2, 1): " << upper_triangular->get(2, 1) << endl;
    cout << "(2, 2): " << upper_triangular->get(2, 2) << endl;
    cout << "(2, 3): " << upper_triangular->get(2, 3) << endl;
    cout << "(3, 1): " << upper_triangular->get(3, 1) << endl;
    cout << "(3, 2): " << upper_triangular->get(3, 2) << endl;
    cout << "(3, 3): " << upper_triangular->get(3, 3) << endl;

    upper_triangular->display();

    return 0;
}