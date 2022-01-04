#include <iostream>

using namespace std;

int input()
{
    int i = 0;
    char c = 0;

    while (c < '0' || c > '9')
    {
        c = getchar_unlocked();
    }

    while (c >= '0' && c <= '9')
    {
        i = i * 10 + (c - '0');
        c = getchar_unlocked();
    }

    return i;
}

int main()
{
    int c = input();

    cout << c << endl;

    return 0;
}