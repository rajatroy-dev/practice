#include <iostream>

using namespace std;

// e^x = 1 + x/1! + x^2/2! + x^3/3! ... till x^n/n!
double e(int x, int n)
{
    static double nm = 1, dm = 1;
    double r;

    if (n == 0)
        return 1;
    else
    {
        r = e(x, n - 1);
        nm = nm * x;
        dm = dm * n;

        return r + nm / dm;
    }
}

int main()
{
    cout << e(5, 20) << endl;
    return 0;
}