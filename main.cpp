#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    srand(time(NULL));

    const int ROWS = 5;
    const int COLS = 5;

    int arr[ROWS][COLS];
    int sum_elements = 0;
    int count = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 30 - 10;
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sum_elements += arr[i][j];
            count += 1;
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << setfill(' ') << setw(2) << arr[i][j] << " ";
        }
        cout << endl;
    }

    double arithmetic_mean = sum_elements / (count * 1.0);

    int min_element = arr[0][0];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (min_element > arr[i][j])
            {
                min_element = arr[i][j];
            }
        }
    }

    int max_element = arr[0][0];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (max_element < arr[i][j])
            {
                max_element = arr[i][j];
            }
        }
    }

    cout << "\nSum of your elements -> " << sum_elements;
    cout << "\nYour arithmetic mean -> " << arithmetic_mean;
    cout << "\nYour minimum element -> " << min_element;
    cout << "\nYour maximum element -> " << max_element;

    return 0;
}
