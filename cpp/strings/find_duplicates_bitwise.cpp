#include <iostream>

using namespace std;

typedef unsigned long long ull; // atleast 64 bytes

void has_duplicates(const char str[])
{
    // A to Z = 65 to 90
    // a to z = 97 to 122
    // 122 - 65 = 57
    // 2^5 = 32 and 2^6 = 64
    // Since, 32 < 57 + 1 < 64
    // So, we consider unsigned long long
    ull a = 0, b = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        b = 1;
        b = b << (str[i] - 65);
        if ((a & b) > 0)
            cout << (char)str[i] << " : is duplicate!" << endl;
        else
            a = a | b;
    }
}

int main()
{
    const char str[] = "rajat roy";
    has_duplicates(str);
    return 0;
}