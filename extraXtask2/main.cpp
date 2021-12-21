#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long hnum;

hnum func(hnum x, hnum n, hnum m)
{
	if (!n)
	{
		return 1;
	}
	if (n % 2)
	{
		return (x * func((x * x) % m, n / 2, m)) % m;
	}
		
	return func((x * x) % m, n / 2, m);
}

int main()
{
	hnum* kArr = new hnum[10];
	hnum* nArr = new hnum[10];
	unsigned short* tArr = new unsigned short[10];
	int count = 0;

	cout << "\tenter k, n and t values:\n";
	while (true)
	{
		cin >> kArr[count];
		cin >> nArr[count];
		cin >> tArr[count];
		cout << endl;

		if (!kArr[count] && !nArr[count] && !tArr[count])
		{
			break;
		}

		count++;
	}
	count++;

	hnum* result = new hnum[count];

	for (int i = 0; i < count - 1; i++)
	{
		hnum lim = nArr[i] * (kArr[i] - 1);
		hnum m = pow(10, tArr[i]);
		hnum x = kArr[i] % m;
		hnum sum = func(x, nArr[i], m);
		result[i] = sum;
	}

	cout << "\tresult:\n";
	for (int i = 0; i < count - 1; i++)
	{
		cout << "Case #" << i + 1 << ": " << result[i] << endl << endl;
	}

	delete[] result;
	delete[] kArr;
	delete[] nArr;
	delete[] tArr;

	return 0;
}