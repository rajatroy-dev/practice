#include <iostream>

using namespace std;

int gcd(int first_number, int second_number)
{
    return second_number == 0 ? first_number : gcd(second_number, first_number % second_number);
}

int main()
{
    cout << gcd(65, 25) << endl;

    return 0;
}