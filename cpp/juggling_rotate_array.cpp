#include <iostream>

using namespace std;

int gcd(int n, int d)
{
    return d == 0 ? n : gcd(d, n % d);
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 12;
    int d = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int hcf = gcd(n, d);

    for (int i = 0; i < hcf; i++)
    {
        int temp = arr[i];
        int j = i;

        while (1)
        {
            int k = j + d;
            if (k >= n)
                k = k - n;

            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }

    display(arr, n);

    return 0;
}