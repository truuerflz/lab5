#include <iostream>
#include "..\StaticLib_Task1\Header.h"
using namespace std;

int main()
{
	cout << "\n\t\tTask: Create a program for finding the coordinates of the saddle point\n\n";

	int rows, cols;
	cout << "enter number of rows(m) of array: "; cin >> rows;
	cout << "enter number of cols(n) of array: "; cin >> cols;
	cout << endl;

	// îáúÿâëåíèå ìàññèâà пувас
	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];

	}

	// îïðåäåëåíèå ìàññèâà
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "arr[" << i << "][" << j << "] is ";
			cin >> arr[i][j];
		}
		cout << endl;
	}

	// âûâîä ìàññèâà
	for (int i = 0; i < rows; i++)
	{
		cout << "\t";
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	int trow = 0, tcol = 0; // êîîðäèíàòû ñåäëîâîé òî÷êè

	// âûçîâ ô-öèè ïîèñêà ñåäëîâîé òî÷êè
	saddlePoint(arr, rows, cols, trow, tcol);

	if (trow == -1)
	{
		cout << endl << endl << "no saddle point" << endl;
	}
	else
	{
		cout << endl << endl << "row: " << trow 
			<< ", col: " << tcol << endl << endl;

		// âûâîä èçìåíåííîãî ìàññèâà
		for (int i = 0; i < rows; i++)
		{
			cout << "\t";
			for (int j = 0; j < cols; j++)
			{
				if (i == trow && j == tcol)
				{
					cout << arr[i][j] << "\t";
				}
				else
				{
					cout << 0 << "\t";
				}
			}
			cout << endl;
		}
	}

	// óäàëåíèå ìàññèâà
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}
