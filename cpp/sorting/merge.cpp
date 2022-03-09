#include <iostream>

using namespace std;

void merge(int arr[], int first, int middle, int end)
{

    int size_of_left_array = middle - first + 1;
    int size_of_right_array = end - middle;

    int left_array[size_of_left_array];
    int right_array[size_of_right_array];

    int i = 0, j = 0, k = first;

    for (i = 0; i < size_of_left_array; i++)
    {
        left_array[i] = arr[first + i];
    }

    for (j = 0; j < size_of_right_array; j++)
    {
        right_array[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = first;

    while (i < size_of_left_array && j < size_of_right_array)
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < size_of_left_array)
    {
        arr[k] = left_array[i];
        i++;
        k++;
    }

    while (j < size_of_right_array)
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }
}

void sort(int arr[], int first, int end)
{
    if (first < end)
    {
        int middle = first + (end - first) / 2;
        sort(arr, first, middle);
        sort(arr, middle + 1, end);
        merge(arr, first, middle, end);
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
    print(arr, 4);
    sort(arr, 0, 4);
    print(arr, 4);
    return 0;
}