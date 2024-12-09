//Напишіть програму, яка створює двовимірний масив і заповнює його за таким принципом:
// користувач вводить число (наприклад, 3); перший елемент масиву набуває значення цього числа;
// наступний елемент масиву набуває значення цього числа + 1 (тобто 4 для нашого прикладу);
// третій елемент масиву — попередній елемент + 1 (тобто 5 для нашого прикладу). Створений масив вивести на екран.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const int RAWS = 9;
    const int COLS = 9;
    int arr[RAWS][COLS];

    int user_number;
    cout << "Enter the number -> ";
    cin >> user_number;

    for (int i = 0; i < RAWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == 0 && j == 0)
            {
                arr[i][j] = user_number;
            }

            else if (j == 0)
            {
                arr[i][j] = arr[i - 1][COLS - 1] + 1;
            }

            else
            {
                arr[i][j] = arr[i][j - 1] + 1;
            }
            cout << setfill(' ') << setw(3) << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}