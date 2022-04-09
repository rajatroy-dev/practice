#include <iostream>
#include <string>

using namespace std;

int is_anagram(const string &first, const string &second)
{
    // A-Z = 65-90 ASCII
    // a-z = 97-122 ASCII
    // 122 - 65 = 57
    // Array size = 57 + 1 = 58
    int rec[58] = {0};

    int is_anagram = 1;

    for (const char &c : first)
    {
        (rec[(int)c - 65])++;
    }

    int int_r = 0;
    for (const char &c : second)
    {
        int_r = (int)c - 65;
        (rec[int_r])--;
        if (rec[int_r] < 0)
        {
            is_anagram = 0;
            break;
        }
    }

    return is_anagram;
}

int main()
{
    if (is_anagram("verbose", "obsErve"))
    {
        cout << "Strings are anagram!" << endl;
    }
    else
    {
        cout << "Strings are not anagram!" << endl;
    }

    return 0;
}