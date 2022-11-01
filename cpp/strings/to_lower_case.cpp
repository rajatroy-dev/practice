#include <iostream>

using namespace std;

// z = 122
// a = 97
// A = 65
// Z = 90
string to_lower_case(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] = str[i] + 32;
        }
    }

    return str;
}

int main()
{
    string str = "RAJAT ROY . ! $# %^";

    cout << to_lower_case(str) << endl;

    return 0;
}