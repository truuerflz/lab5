#include <iostream>
using namespace std;

typedef unsigned long num;

num func(num n)
{
	if (!n)
	{
		return 0;
	}
	if (n % 2)
	{
		return n + func(n - 1);
	}
	else
	{
		int r = n;
		while (!(r % 2))
		{
			r /= 2;
		}
		return r + func(n - 1);
	}
}

int main()
{
	int k;
	cout << "number of values: "; cin >> k;
	cout << endl;
	num* nArr = new num[k];
	num* result = new num[k];

	cout << "\tenter n values:\n";
	for (int i = 0; i < k; i++)
	{
		cin >> nArr[i];
		result[i] = func(nArr[i]);
	}

	cout << endl << "\tresult:\n";
	for (int i = 0; i < k; i++)
	{
		cout << result[i] << endl;
	}

	delete[] result;
	delete[] nArr;
	return 0;
}