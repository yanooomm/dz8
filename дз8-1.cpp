/* DArray9 Задана матрица А размерности n*n. Зеркально 
отразить ее относительно побочной диагонали */

#include <iostream>

using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int m;
    cout<<"Введите размер матрицы ";
    cin>>m;
    int i, j;
    int** a = new int* [m];
    for (i = 0;i < m;i++)
    {
        a[i] = new int[m];
        for (j = 0; j < m; j++)
        {
            a[i][j] = rand() % 11;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < i; j++)
        {
            const int x = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = x;
        }
    }
    cout << endl;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++)
        delete[] a[i];
    delete[] a;
}

/*
Введите размер матрицы 4
10      3       10      3
2       5       4       4
8       4       2       2
1       9       9       8

10      2       8       1
3       5       4       9
10      4       2       9
3       4       2       8
*/


/*
Введите размер матрицы 3
2       2       6
1       3       2
6       6       6

2       1       6
2       3       6
6       2       6
*/
