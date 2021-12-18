#include <iostream>

using namespace std;

int binary_search(int *arr, int arr_start_pos, int arr_end_pos, int element)
{
    int arr_middle_pos = 0;
    while (arr_start_pos <= arr_end_pos)
    {
        arr_middle_pos = arr_start_pos + (arr_end_pos - arr_start_pos) / 2;

        if (element == arr[arr_middle_pos])
            return arr_middle_pos;
        else if (element < arr[arr_middle_pos])
            arr_end_pos = arr_middle_pos - 1;
        else if (element > arr[arr_middle_pos])
            arr_start_pos = arr_middle_pos + 1;
        else
            break;
    }
    return -1;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int element = 9;
    cout << "Found " << element << " at position " << binary_search(arr, 0, 8, element) << endl;

    return 0;
}