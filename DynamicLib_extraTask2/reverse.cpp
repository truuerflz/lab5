extern "C" __declspec(dllexport) void Reverse(double** arr, int rows, int cols)
{
	int x;
	bool middle = false;
	if (rows % 2) // Определение среднего ряда, если такой есть
	{
		x = rows / 2 + 1;
		middle = true;
	}
	else
	{
		x = rows / 2;
	}
	int y = cols;

	for (int i = 0; i < x; i++)
	{
		if (i == x - 1 && middle) 
		{
			y /= 2;
		}
		for (int j = 0; j < y; j++) // замена местами элементов
		{
			double temp = arr[i][j];
			arr[i][j] = arr[rows - 1 - i][cols - j - 1];
			arr[rows - 1 - i][cols - j - 1] = temp;
		}
	}
}
