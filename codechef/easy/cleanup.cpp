#include <iostream>

using namespace std;

int input()
{
    int i = 0;
    char c = 0;

    while (c < '0' || c > '9')
    {
        c = getchar();
    }

    while (c >= '0' && c <= '9')
    {
        i = i * 10 + (c - '0');
        c = getchar();
    }

    return i;
}

int main()
{
    int tests, chores, done;
    int *array;
    cin >> tests;

    while (tests--)
    {
        chores = input();
        done = input();
        array = new int[chores + 1];

        for (int j = 1; j <= chores; j++)
        {
            array[j] = j;
        }

        for (int j = 0; j < done; j++)
        {
            int f = input();
            array[f] = 0;
        }

        int count = 0;
        string chef = "";
        string assistant = "";
        for (int j = 1; j <= chores; j++)
        {

            if (array[j] != 0)
            {
                if (count % 2 == 0)
                    chef.append(to_string(j) + " ");
                else
                    assistant.append(to_string(j) + " ");
                count++;
            }
        }

        cout << chef << endl;
        cout << assistant << endl;
    }

    return 0;
}