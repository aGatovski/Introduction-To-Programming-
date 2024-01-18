#include <iostream>

void findCoordinates(int n, int** matrix,int length) {

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (matrix[i][j] == n) std::cout << i << " " << j;
		}
	}

}

int main()
{
	int numberS;
	std::cin >> numberS;
	int** matrix = new int* [10];

	for (int i = 0; i < 3; i++)
	{
		 matrix[i] = new int[3];

		for (int j = 0; j < 3; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
	/*
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}
	*/
	findCoordinates(numberS, matrix, 3);
	return 0;
}
