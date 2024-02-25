#include <iostream>

int main()
{
	int n,m;
	
	std::cin >> n >> m;
	int p = 0;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < m; j++)
		{
			p++;
			std::cout << p << " ";

		}
		std::cout<<std::endl;
	}
	
}
