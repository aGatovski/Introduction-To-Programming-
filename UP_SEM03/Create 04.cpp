#include <iostream>

int main()
{
	int n;
	
	std::cin >> n;
	int fact = 1;
	for (int i = n; i  >= 1;  i--)
	{
		fact *= i;
	}
	std::cout << fact;
}
