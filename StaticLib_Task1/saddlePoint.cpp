void saddlePoint(int** arr, int rows, int cols, int& trow, int& tcol)
{
	int minRow;

	for (int i = 0; i < rows; i++)
	{
		bool isSaddle = true;
		minRow = arr[i][0];
		trow = i;

		// наименьшее из строки
		for (int j = 0; j < cols; j++)
		{
			if (minRow >= arr[i][j])
			{
				minRow = arr[i][j];
				tcol = j;
			}
		}

		// если строка из равных чисел
		if (minRow == arr[i][0] && tcol != 0)
		{
			if (i == rows - 1)
			{
				trow = -1;
			}
			continue;
		}

		for (int k = 0; k < rows; k++)
		{
			if (minRow <= arr[k][tcol] && k != trow)
			{
				isSaddle = false;
				break;
			}
		}

		if (isSaddle)
		{
			return;
		}
		else
		{
			trow = -1; // no saddle point
		}

	}

}