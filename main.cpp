#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    const int FIRST_RAWS = 5;
    const int FIRST_COLS = 10;
    const int SECOND_RAWS = 5;
    const int SECOND_COLS = 5;

    int first_arr[FIRST_RAWS][FIRST_COLS];
    int second_arr[SECOND_RAWS][SECOND_COLS];

    cout << "\nYour first array ->\n" << endl;

    for (int i = 0; i < FIRST_RAWS; i++)
    {
        for (int j = 0; j < FIRST_COLS; j++)
        {
            first_arr[i][j] = rand() % 51;
            cout << setfill(' ') << setw(2) << first_arr[i][j] << "   ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "\nYour second array ->\n" << endl;

    for (int i = 0; i < SECOND_RAWS; i++)
    {
        for (int j = 0; j < SECOND_COLS; j++)
        {
            second_arr[i][j] = first_arr[i][j * 2] + first_arr[i][j * 2 + 1];
            cout << setfill(' ')<< setw(3) << second_arr[i][j] << "   ";
        }
        cout << endl;
    }

    return 0;
}