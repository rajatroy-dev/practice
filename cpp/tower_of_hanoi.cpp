#include <iostream>

using namespace std;

void tower_of_hanoi(int A, int B, int C, int n)
{
    if (n > 0)
    {
        tower_of_hanoi(A, C, B, n - 1);
        cout << "( " << A << ", " << C << " )" << endl;
        tower_of_hanoi(B, A, C, n - 1);
    }
}

int main()
{
    tower_of_hanoi(1, 2, 3, 3);
    return 0;
}