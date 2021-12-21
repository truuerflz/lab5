#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

void output(double** arr, int rows, int cols)
{
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
}

void zero(double** arr, int rows, int cols)
{
	int count = 0;

	cout << "\tZero elements:\n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j])
			{
				continue;
			}
			else
			{
				count++;
				cout << count << ": i = " << i
					<< ", j = " << j << ";\n";
			}
		}
	}

	if (!count)
	{
		cout << "no zero elements" << endl;
	}

	cout << endl;
}

int main()
{
	HINSTANCE load;
	load = LoadLibrary(L"DynamicLib_extraTask2.dll");
	typedef void(*reverse) (double**, int, int);
	reverse Reverse;
	Reverse = (reverse)GetProcAddress(load, "Reverse");

	cout << "\n\t\tTask: 1.Determine if there are elements with zero value among elements of array;\n\t\t2.Reverse array\n\n";

	srand((int)time(NULL));

	int rows, cols;
	cout << "enter number of rows(n) of array: "; cin >> rows;
	cout << "enter number of cols(k) of array: "; cin >> cols;
	cout << endl;

	// объявление массива
	double** arr = new double* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new double[cols];

	}

	// определение массива
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			double f = (double)(rand() % 13) / (rand() % 20 + 1.0);
			arr[i][j] = f * 10;
		}
	}

	cout << fixed << setprecision(2);

	// вывод массива
	output(arr, rows, cols);

	// действия с нулевыми элементами
	zero(arr, rows, cols);

	Reverse(arr, rows, cols);
	output(arr, rows, cols);

	// удаление массива
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}


	delete[] arr;
	FreeLibrary(load);
	return 0;
}

