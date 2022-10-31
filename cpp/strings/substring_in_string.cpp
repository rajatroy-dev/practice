#include <iostream>

using namespace std;

int substring(string str, string sub_str)
{
    int str_length = str.length();
    int sub_str_length = sub_str.length();

    /*
        Example:
        Let us consider this as the string:
        "This program is used to find the substring from a string."

        In the above string if we try to find "from".

        So, if we consider "from" as 1 character then the total
        length of the string is 57 - 4 = 53 + 1 = 54
        Since, in array we start with 0, so we can consider 53.
    */
    for (int i = 0; i <= str_length - sub_str_length; i++)
    {
        int j;
        for (j = 0; j < sub_str_length; j++)
        {
            if (str[i + j] != sub_str[j])
            {
                break;
            }
        }

        if (j == sub_str_length)
            return i;
    }

    return -1;
}

int main()
{
    string str = "This program is used to find the substring from a string.";
    string sub_str = "from";

    cout << substring(str, sub_str) << endl;

    return 0;
}