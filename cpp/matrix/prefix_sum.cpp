#include <iostream>

#define ROW_SIZE 4
#define COLUMN_SIZE 5

using namespace std;

void calculate_prefix_sum(int matrix[][COLUMN_SIZE])
{
    int prefix_sum[ROW_SIZE][COLUMN_SIZE];

    // Element (0, 0)
    prefix_sum[0][0] = matrix[0][0];

    // First row
    for (int j = 1; j < COLUMN_SIZE; j++)
    {
        prefix_sum[0][j] = prefix_sum[0][j - 1] + matrix[0][j];
    }

    // First column
    for (int i = 1; i < ROW_SIZE; i++)
    {
        prefix_sum[i][0] = prefix_sum[i - 1][0] + matrix[i][0];
    }

    // Rest of the rows and columns
    for (int i = 1; i < ROW_SIZE; i++)
    {
        for (int j = 1; j < COLUMN_SIZE; j++)
        {
            prefix_sum[i][j] = prefix_sum[i][j - 1] + prefix_sum[i - 1][j] - prefix_sum[i - 1][j - 1] + matrix[i][j];
        }
    }

    // Print
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COLUMN_SIZE; j++)
        {
            cout << prefix_sum[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a[4][5] = {{1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1}};

    calculate_prefix_sum(a);
    return 0;
}