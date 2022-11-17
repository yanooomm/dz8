/* DArray12 Поменять максимальный элемент матрицы В размерности N x M 
с его первым элементом, а минимальный с с последним. В матрице только
один максимальный и один минимальный элемент.*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество строк" << endl;
	cin >> n;
	cout << "Введите количество столбцов" << endl;
	int m;
	cin >> m;
	cout << endl;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 90;
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	int imax = 0; 
	int jmax = 0;
	int imin = 0;
	int jmin = 0;
	int max = a[0][0];
	int min = a[0][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				imax = i;
				jmax = j;
			}
			if (a[i][j] < min)
			{
				min = a[i][j];
				imin = i;
				jmin = j;
			}
		}

			

	int Temp1 = a[0][0];
	a[0][0] = a[imax][jmax];
	a[imax][jmax] = Temp1;

	int Temp2 = a[n-1][m-1];
	a[n-1][m-1] = a[imin][jmin];
	a[imin][jmin] = Temp2;



	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}

	cout << endl;
	cout << "max" << " " << max;
	cout << endl;
	cout << "min" << " " << min;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}

/*
Введите количество строк
4
Введите количество столбцов
5

8       9       9       1       7
5       5       10      1       0
7       7       5       8       6
7       3       7       9       2

10      9       9       1       7
5       5       8       1       2
7       7       5       8       6
7       3       7       9       0

max 10
min 0
*/

/*
Введите количество строк
4
Введите количество столбцов
6

41      17      34      40      89      64
48      18      52      74      35      65
61      87      61      41      25      62
57      36      81      24      32      63

89      63      34      40      41      64
48      18      52      74      35      65
61      87      61      41      25      62
57      36      81      24      32      17

max 89
min 17
*/