#include <iostream>
#define STRING_SIZE 100

using namespace std;

void permutation_of_string(char *str, int char_pos)
{
    static int flag[STRING_SIZE] = {0};
    static char new_string[STRING_SIZE];

    if (str[char_pos] == '\0')
    {
        new_string[char_pos] = '\0';
        cout << new_string << endl;
    }
    else
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (flag[i] == 0)
            {
                new_string[char_pos] = str[i];
                flag[i] = 1;
                permutation_of_string(str, char_pos + 1);
                flag[i] = 0;
            }
        }
    }
}

int main()
{
    char str[] = "rajat";
    permutation_of_string(str, 0);

    return 0;
}