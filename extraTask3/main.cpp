#include <iostream>
using namespace std;

void evenOdd(int** arr, int rows, int cols)
{
	int size = cols / 2 * rows; // макс кол-во элементов
	int* newArr = new int[size];

	int count = 0;
	int sum = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 1; j < cols; j += 2)
		{
			if (arr[i][j] % 2)
			{
				newArr[count] = arr[i][j];
				sum += newArr[count];
				count++;
			}
		}
	}
	double average = (double)sum / count;

	cout << "new array:\n\t";
	for (int i = 0; i < count; i++)
	{
		cout << newArr[i] << "\t";
	}
	cout << "\naverage value is " << average << endl;

	delete[] newArr;
}

int main()
{
	cout << "\n\t\tTask: Create a dynamic array from elements, located in even columns of this array and having an odd value\n\n";

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


	evenOdd(arr, rows, cols);

	// удаление массива
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}
