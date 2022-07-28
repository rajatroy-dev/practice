#include <iostream>

using namespace std;

int compare(const char *first, const char *second)
{
    int result = 0;
    for (int i = 0, j = 0; first[i] != '\0' || second[j] != '\0'; i++, j++)
    {
        if (first[i] < second[j])
        {
            result = -1;
            break;
        }
        else if (first[i] > second[j])
        {
            result = 1;
            break;
        }
    }

    return result;
}

int main()
{
    const char *first = "painters";
    const char *second = "painters";
    cout << compare(first, second) << endl;
    return 0;
}