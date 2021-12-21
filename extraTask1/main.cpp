#include <iostream>
using namespace std;

void diagArr(int** arr, int rows, int cols)
{
	int temp, n;
	temp = rows > cols ? cols : rows; // т.к. матрица необязательно квадратная, то диагональ упрется в границу
	n = temp;
	for (int i = 0; i < temp; i++)
	{
		if (arr[i][i] % 2)
		{
			n--;
		}
	}
	int* dArr = new int[n];

	int k = 0;
	for (int i = 0; i < n; i++)
	{
		while (arr[k][k] % 2)
		{
			k++;
		}

		dArr[i] = arr[k][k];
		k++;
	}

	if (n)
	{
		cout << "diagonal filled array: " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << dArr[i] << "\t";
		}

		int prod = 1;

		for (int i = 0; i < n; i++)
		{
			prod *= dArr[i];
		}

		cout << endl << endl << "product of this array: " << prod << endl;
	}
	else
	{
		cout << "all elements are odd" << endl;
	}
	

	delete[] dArr;
}

int main()
{
	cout << "\n\t\tTask: Create a dynamic array from elements located on the main diagonal of the matrix and having an even value\n\n";

	int rows, cols;
	cout << "enter number of rows(n) of array: "; cin >> rows;
	cout << "enter number of cols(k) of array: "; cin >> cols;
	cout << endl;

	// объявление массива
	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];

	}

	// определение массива
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "arr[" << i << "][" << j << "] is ";
			cin >> arr[i][j];
		}
		cout << endl;
	}

	// вывод массива
	for (int i = 0; i < rows; i++)
	{
		cout << "\t";
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	diagArr(arr, rows, cols);

	// удаление массива
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}