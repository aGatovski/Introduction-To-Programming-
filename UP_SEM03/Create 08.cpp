#include <iostream>

int main()
{
	int number;
	std::cin >> number;
	for (int i = 5; i < number; i++)
	{
		for (int j = 4; j < i; j++)
		{
			for (int k = 3; k < j; k++)
			{
				int piT = k * k + j * j;
				if (piT == i * i) std::cout << k << " " << j << " " << i << " " << std::endl;
			}
		}
	}
	
}
