#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = start;

    for (int i = start; i < end; i++)
    {
        if (arr[i] <= arr[end])
        {
            swap(&arr[i], &arr[pivot]);
            pivot++;
        }
    }
    swap(&arr[end], &arr[pivot]);

    return pivot;
}

void sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);

        sort(arr, start, pivot - 1);
        sort(arr, pivot + 1, end);
    }
}

void print(int arr[], int end)
{
    cout << "[ ";
    for (int i = 0; i < end; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[end] << " ]" << endl;
}

int main()
{
    int arr[] = {5, 2, 7, 1, 9};
    sort(arr, 0, 4);
    print(arr, 4);
    return 0;
}