#include <iostream>

using namespace std;

// z = 122
// a = 97
// A = 65
// Z = 90
string to_upper_case(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] = str[i] - 32;
        }
    }

    return str;
}

int main()
{
    string str = "rajat roy . ! $# %^";

    cout << to_upper_case(str) << endl;

    return 0;
}