#include <iostream>

int main()
{
	int n;
	
	std::cin >> n;
	int qNum = n * n;
	int newNumber = 0;
	int c = 1;
	while (qNum!=0)
	{
		newNumber =newNumber*10 +  qNum % 10 ;
		qNum/= 10;
		
	}
	std::cout << newNumber << std::endl;
}
