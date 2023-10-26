#include <iostream>

int main()
{
	int a;
	char c;
	char s = ' ';
	std::cin >> a >> c;
	for (int row= 0; row<a-1 ; row++)
	{
		for (int space = row; space < a-1; space++)
		{
			std::cout << s;
		}
		for (int i = 0; i < row*2+1; i++)
		{
			std::cout << c;
		}
		std::cout << std::endl;
	}
	for (int row = a; row > 0; row--)
	{	
		for (int space = 0;space <a-row  ; space++)
		{
			std::cout << s;
		}
		for (int i =row*2-1; i >0; i--)
		{
			std::cout << c;
		}
		std::cout << std::endl;
	}
}
