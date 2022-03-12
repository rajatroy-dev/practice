#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull power(int m, int n)
{
    return n > 0 ? m * power(m, n - 1) : 1;
}

int main()
{
    cout << power(3, 9) << endl;
    return 0;
}