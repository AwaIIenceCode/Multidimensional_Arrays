#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

const int RAWS = 5;
const int COLS = 5;

void array_filling(int arr[][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 26;
        }
    }
}

void printArray(int arr[][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void shiftLeft(int arr[][COLS], int rows, int cols, int shifts)
{
    shifts %= cols;
    for (int i = 0; i < rows; i++)
    {
        for (int s = 0; s < shifts; s++)
        {
            int temp = arr[i][0];
            for (int j = 0; j < cols - 1; j++)
            {
                arr[i][j] = arr[i][j + 1];
            }
            arr[i][cols - 1] = temp;
        }
    }
}

void shiftRight(int arr[][COLS], int rows, int cols, int shifts)
{
    shifts %= cols;
    for (int i = 0; i < rows; i++)
    {
        for (int s = 0; s < shifts; s++)
        {
            int temp = arr[i][cols - 1];
            for (int j = cols - 1; j > 0; j--)
            {
                arr[i][j] = arr[i][j - 1];
            }
            arr[i][0] = temp;
        }
    }
}

void shiftUp(int arr[][COLS], int rows, int cols, int shifts)
{
    shifts %= rows;
    for (int s = 0; s < shifts; s++)
    {
        for (int j = 0; j < cols; j++)
        {
            int temp = arr[0][j];
            for (int i = 0; i < rows - 1; i++)
            {
                arr[i][j] = arr[i + 1][j];
            }
            arr[rows - 1][j] = temp;
        }
    }
}

void shiftDown(int arr[][COLS], int rows, int cols, int shifts)
{
    shifts %= rows;
    for (int s = 0; s < shifts; s++)
    {
        for (int j = 0; j < cols; j++)
        {
            int temp = arr[rows - 1][j];
            for (int i = rows - 1; i > 0; i--)
            {
                arr[i][j] = arr[i - 1][j];
            }
            arr[0][j] = temp;
        }
    }
}

int main()
{
    srand(time(NULL));

    int arr[RAWS][COLS];

    array_filling(arr, RAWS, COLS);
    cout << "Original array:\n";
    printArray(arr, RAWS, COLS);

    int direction, shifts;
    cout << "\nEnter the number of shifts -> ";
    cin >> shifts;
    cout << "Choose direction (1 - left, 2 - right, 3 - up, 4 - down) -> ";
    cin >> direction;

    switch (direction)
    {
        case 1:
        {
            shiftLeft(arr, RAWS, COLS, shifts);
            break;
        }

        case 2:
        {
            shiftRight(arr, RAWS, COLS, shifts);
            break;
        }

        case 3:
        {
            shiftUp(arr, RAWS, COLS, shifts);
            break;
        }

        case 4:
        {
            shiftDown(arr, RAWS, COLS, shifts);
            break;
        }

        default:
        {
            cout << "Invalid direction!";
            return 0;
        }
    }

    cout << "\nArray after shift:\n";
    printArray(arr, RAWS, COLS);

    return 0;
}