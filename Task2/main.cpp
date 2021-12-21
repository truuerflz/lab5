#include <iostream>
using namespace std;

void negCheck(const int* arr, int a, int n, bool &isNegative)
{
	if (arr[a] >= 0)
	{
		cout << "Y[" << a << "] = " << arr[a] << endl;
		isNegative = false;
	}
	
	if (a < n - 1)
	{
		negCheck(arr, a + 1, n, isNegative);
	}
}

int main()
{
	cout << "\n\t\tTask: Check, that every element of array satisfy the condition Yi < 0\n\n";

	srand((int)time(NULL));

	int n;
	cout << "\tenter number of elements of array: "; cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 - 90; // числа от -90 до 9
		cout << arr[i] << "\t";
	}
	cout << endl << endl;

	bool isNegative = true;
	int a = n / 2;

	negCheck(arr, 0, a, isNegative); //1-я половина
	negCheck(arr, a, n, isNegative); //2-я половина

	if (isNegative)
	{
		cout << endl << "all elements of array are negative" << endl;
	}
	else
	{
		cout << endl << "not all elements of array are negative" << endl;
	}

	delete[] arr;

	return 0;
}
