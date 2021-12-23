#include <iostream>

using namespace std;

class LowerTriangular
{
    int *array;
    int rows_columns;

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
        {
            int index = (m * (m - 1)) / 2 + n - 1;
            this->array[index] = x;
        }
    }

    int get(int m, int n)
    {
        if (n <= m)
        {
            int index = (m * (m - 1)) / 2 + n - 1;
            return this->array[index];
        }
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
                    int index = (m * (m - 1)) / 2 + n - 1;
                    cout << this->array[index] << " ";
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