#include <iostream>

using namespace std;

typedef unsigned long long ull;

// a function calls itself 2 or more times
ull tree(ull n)
{
    static ull a = 1, b = 1;

    if (n <= 1)
        return 1;

    a = a + tree(n - 1);
    b = b + tree(n - 2);

    return a + b;
}

int main()
{
    cout << tree(5) << endl;

    return 0;
}