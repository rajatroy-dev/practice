#include <iostream>

using namespace std;

// e^x = 1 + x/1! + x^2/2! + x^3/3! ... till x^n/n!
double e(int x, int n)
{
    double result = 1;

    while (n > 0)
    {
        result = 1 + result * x / n;
        n--;
    }

    return result;
}

int main()
{
    cout << e(5, 20) << endl;
    return 0;
}