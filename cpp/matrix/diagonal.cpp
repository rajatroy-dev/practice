#include <iostream>

using namespace std;

// Diagonal matrix is a square matrix whose diagonal elements are non-zero rest all elements are zero.
class Matrix
{
    int *array;
    int array_size;

public:
    Matrix(int array_size)
    {
        this->array_size = array_size;
        this->array = new int[array_size];
    }

    void set(int m, int n, int x)
    {
        if (m == n && m <= array_size)
            this->array[m - 1] = x;
    }

    int get(int m, int n)
    {
        if (m == n && m <= array_size)
            return this->array[m - 1];
        return 0;
    }

    void display()
    {
        for (int i = 0; i < array_size; i++)
        {
            for (int j = 0; j < array_size; j++)
            {
                if (i == j)
                    cout << this->array[i] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix *matrix = new Matrix(3);

    matrix->set(1, 1, 1);
    matrix->set(1, 2, 2);
    matrix->set(1, 3, 3);
    matrix->set(2, 1, 1);
    matrix->set(2, 2, 2);
    matrix->set(2, 3, 3);
    matrix->set(3, 1, 1);
    matrix->set(3, 2, 2);
    matrix->set(3, 3, 3);

    cout << "(1, 1): " << matrix->get(1, 1) << endl;
    cout << "(1, 2): " << matrix->get(1, 2) << endl;
    cout << "(1, 3): " << matrix->get(1, 3) << endl;
    cout << "(2, 1): " << matrix->get(2, 1) << endl;
    cout << "(2, 2): " << matrix->get(2, 2) << endl;
    cout << "(2, 3): " << matrix->get(2, 3) << endl;
    cout << "(3, 1): " << matrix->get(3, 1) << endl;
    cout << "(3, 2): " << matrix->get(3, 2) << endl;
    cout << "(3, 3): " << matrix->get(3, 3) << endl;

    matrix->display();
    return 0;
}