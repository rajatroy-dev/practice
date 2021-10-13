#include <iostream>
#define ARRAY_SIZE 100

using namespace std;

int fib_arr[ARRAY_SIZE] = {0};

int fibonacci(int n)
{
    if (n <= 1)
    {
        fib_arr[n] = n;
        return n;
    }
    else
    {
        if (fib_arr[n - 1] == 0)
            fib_arr[n - 1] = fibonacci(n - 1);
        if (fib_arr[n - 2] == 0)
            fib_arr[n - 2] = fibonacci(n - 2);

        return fib_arr[n - 1] + fib_arr[n - 2];
    }
}

int main()
{
    int result = fibonacci(5);
    cout << result << endl;
    return 0;
}