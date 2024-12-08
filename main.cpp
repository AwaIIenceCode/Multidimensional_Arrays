#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    srand(time(NULL));
    const int ROWS = 3;
    const int COLS = 4;
    int arr[ROWS][COLS];

    int all_sum = 0;

    for (int i = 0; i < ROWS; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 12;
            cout << setfill(' ') << setw(2) << arr[i][j] << "   ";
            all_sum += arr[i][j];
            row_sum += arr[i][j];
        }
        cout << "|  " << row_sum;
        cout << endl;
    }

    cout << "__________________________" << endl;

    for (int j = 0; j < COLS; j++)
    {
        int col_sum = 0;
        for (int i = 0; i < ROWS; i++)
        {
                col_sum += arr[i][j];
        }
        cout << col_sum << "   ";
    }
    cout << " |  " << all_sum;

    return 0;
}