#include <iostream>

using namespace std;

// A symmetric matrix is a square matrix that is equal to its transpose. M(i, j) = M(j, i).
class Symmetric
{
    int *array;
    int rows_columns;

    int get_index(int m, int n)
    {
        return (n * (n - 1)) / 2 + m - 1;
    }

public:
    Symmetric(int rows_columns)
    {
        int array_size = (rows_columns * (rows_columns + 1)) / 2;
        this->array = new int[array_size];
        this->rows_columns = rows_columns;
    }

    ~Symmetric()
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

        return this->array[this->get_index(n, m)];
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
    Symmetric *symmetric = new Symmetric(3);

    symmetric->set(1, 1, 1);
    symmetric->set(1, 2, 2);
    symmetric->set(1, 3, 3);
    symmetric->set(2, 1, 1);
    symmetric->set(2, 2, 2);
    symmetric->set(2, 3, 3);
    symmetric->set(3, 1, 1);
    symmetric->set(3, 2, 2);
    symmetric->set(3, 3, 3);

    cout << "(1, 1): " << symmetric->get(1, 1) << endl;
    cout << "(1, 2): " << symmetric->get(1, 2) << endl;
    cout << "(1, 3): " << symmetric->get(1, 3) << endl;
    cout << "(2, 1): " << symmetric->get(2, 1) << endl;
    cout << "(2, 2): " << symmetric->get(2, 2) << endl;
    cout << "(2, 3): " << symmetric->get(2, 3) << endl;
    cout << "(3, 1): " << symmetric->get(3, 1) << endl;
    cout << "(3, 2): " << symmetric->get(3, 2) << endl;
    cout << "(3, 3): " << symmetric->get(3, 3) << endl;

    symmetric->display();

    return 0;
}