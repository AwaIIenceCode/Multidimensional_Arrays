#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const int RAWS = 3;
    const int COLS = 3;
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
                arr[i][j] = arr[i - 1][COLS - 1] * 2;
            }

            else
            {
                arr[i][j] = arr[i][j - 1] * 2;
            }
            cout << setfill(' ') << setw(4) << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}