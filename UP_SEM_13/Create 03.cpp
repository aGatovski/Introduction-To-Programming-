#include<iostream>

int findTheDifferentNumberIdx(unsigned* xArr, int* yArr, unsigned length) {

	for (unsigned i = 0; i < length; i++)
	{
		if (xArr[i] != yArr[i]) {
			return i;

		}
	}
	 return -1;
}

int main() {
	int length;
	std::cin >> length;

	unsigned* xArr = new unsigned[length];
	int* yArr = new int[length+1];


	for (unsigned i = 0; i < length; i++)
	{
		std::cin >> xArr[i];
	}


	for (unsigned i = 0; i < length+1; i++)
	{
		std::cin >> yArr[i];
	}

	std::cout << findTheDifferentNumberIdx(xArr, yArr, length);
}
