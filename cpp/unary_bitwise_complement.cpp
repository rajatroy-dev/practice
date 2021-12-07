#include <iostream>

using namespace std;

int main()
{
    int x = 2;
    int y = ~x - 1; // ~x = (-x) - 1

    cout << y << endl;

    return 0;
}