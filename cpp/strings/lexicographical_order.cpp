#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull factorial(int number)
{
    return number <= 1 ? 1 : number * factorial(number - 1);
}

int number_of_smaller_characters_on_the_right(string str, int first_character_position)
{
    int count = 0;
    for (int j = first_character_position + 1; j < str.size(); j++)
    {
        if (str[j] <= str[first_character_position])
        {
            count++;
        }
    }

    return count;
}

int lexicographical_order(string str)
{
    int order = 1;
    int count = 0;
    int str_size = str.size();
    ull _factorial = factorial(str_size);

    for (int i = 0; i < str_size; i++)
    {
        _factorial /= (str_size - i);
        count = number_of_smaller_characters_on_the_right(str, i);
        order = order + (count * _factorial);
    }

    return order;
}

int main()
{
    string str = "string";

    cout << lexicographical_order(str) << endl;

    return 0;
}