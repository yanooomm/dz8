/* Написать программу для вычитания двух длинных целых чисел*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n, a[30][30] = {}, m;
    m = 3;
    cout << "Введите длину чисел" << endl;
    cin >> n;

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10;
            if (j == 0)
                a[i][j] = 0;
            cout << " " << a[i][j];
        }
        cout << endl;
    }

    int k = 0;
    int s = 0;
    for (int j = n - 1; j > 0; j--)
    {

        if (k == 1)
        {
            a[2][j] -= 1;
            k = 0;
        }
        if (a[1][1] > a[0][1])
        {
            s = 1;
            if (a[1][j] < a[0][j])
            {
                a[2][j] += (a[1][j] + 10) - a[0][j];
                k += 1;
            }
            else a[2][j] += a[1][j] - a[0][j];
        }
        else {
            if (a[1][j] > a[0][j])
            {
                a[2][j] += ((a[0][j]) + 10) - a[1][j];
                k += 1;
            }
            else 
                if (a[1][j] < a[0][j])
                    a[2][j] += a[0][j] - a[1][j];
        }
        if (a[2][j] == -1)
        {
            a[2][j] = 0;
            k += 1;
        }
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << " " << a[i][j];
        cout << endl;
    }

    if (s == 1)
    {
        cout << "Ответ = -";
        for (int j = 1; j < n; j++)
            cout << a[2][j];
    }
    else
    {
        cout << "Ответ = ";
        for (int j = 1; j < n; j++)
            cout << a[2][j];
    }

}

/*
Введите длину чисел
7
 0 0 2 7 2 9 7
 0 7 4 6 3 1 0

 0 0 2 7 2 9 7
 0 7 4 6 3 1 0
 0 7 1 9 0 1 3
Ответ = -719013
*/

/*
Введите длину чисел
8
 0 8 2 7 1 3 9 8
 0 6 0 7 0 3 4 4

 0 8 2 7 1 3 9 8
 0 6 0 7 0 3 4 4
 0 2 2 0 1 0 5 4
Ответ = 2201054
*/

