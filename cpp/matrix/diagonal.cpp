#include <iostream>

using namespace std;

// Diagonal diagonal is a square diagonal whose diagonal elements are non-zero rest all elements are zero.
class Diagonal
{
    int *array;
    int array_size;

public:
    Diagonal(int array_size)
    {
        this->array_size = array_size;
        this->array = new int[array_size];
    }

    ~Diagonal()
    {
        delete[] this->array;
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
    Diagonal *diagonal = new Diagonal(3);

    diagonal->set(1, 1, 1);
    diagonal->set(1, 2, 2);
    diagonal->set(1, 3, 3);
    diagonal->set(2, 1, 1);
    diagonal->set(2, 2, 2);
    diagonal->set(2, 3, 3);
    diagonal->set(3, 1, 1);
    diagonal->set(3, 2, 2);
    diagonal->set(3, 3, 3);

    cout << "(1, 1): " << diagonal->get(1, 1) << endl;
    cout << "(1, 2): " << diagonal->get(1, 2) << endl;
    cout << "(1, 3): " << diagonal->get(1, 3) << endl;
    cout << "(2, 1): " << diagonal->get(2, 1) << endl;
    cout << "(2, 2): " << diagonal->get(2, 2) << endl;
    cout << "(2, 3): " << diagonal->get(2, 3) << endl;
    cout << "(3, 1): " << diagonal->get(3, 1) << endl;
    cout << "(3, 2): " << diagonal->get(3, 2) << endl;
    cout << "(3, 3): " << diagonal->get(3, 3) << endl;

    diagonal->display();
    return 0;
}