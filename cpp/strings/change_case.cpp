#include <iostream>

using namespace std;

int main()
{
    char str[] = "weL7ome";

    for (int j = 0; str[j] != '\0'; j++)
    {
        // A-Z = 65 to 90
        // a-z = 97 to 122
        // 0-9 = 48 to 57
        // a - A = 97 - 65 = 32
        // b - B = 98 - 66 = 32
        if (str[j] >= 65 && str[j] <= 90)
        {
            str[j] = str[j] + 32;
        }
        else if (str[j] >= 97 && str[j] <= 122)
        {
            str[j] = str[j] - 32;
        }
    }

    cout << str << endl;

    return 0;
}