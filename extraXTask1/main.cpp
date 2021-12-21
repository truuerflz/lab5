#include <iostream>
using namespace std;

long func(long p, long q, long n, bool isDecade)
{
	if (p > q)
	{
		return 0;
	}

	if (n % 10 > 0) // Не пройдут десятки(10, 20, ...)
	{
		n %= 10;
	}
	else if (!n){}
	else
	{
		n = func(p, q, n / 10, true);
	}
	if (n < p && isDecade)
	{
		return n;
	}
	return n + func(p + 1, q, p + 1, false);
	
}


int main()
{
	long* pArr = new long[10];
	long* qArr = new long[10];
	int count = 0;

	cout << "\tenter p and q values:\n";
	while (true)
	{
		cin >> pArr[count];
		cin >> qArr[count];
		cout << endl;
		count++;
		if (pArr[count - 1] < 0)
		{
			break;
		}
		if (pArr[count - 1] > qArr[count - 1])
		{
			cout << "error! q < p, enter once again..." << endl << endl;
			count--;
		}
	}

	long* result = new long[count - 1];

	cout << "\tresult:\n";
	for (int i = 0; i < count - 1; i++)
	{
		result[i] = func(pArr[i], qArr[i], pArr[i], false);
		cout << result[i] << endl;
	}

	delete[] result;
	delete[] pArr;
	delete[] qArr;

	return 0;
}
