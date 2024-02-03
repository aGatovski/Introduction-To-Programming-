#include<iostream>



void returnIndexOfPlace(int* array,unsigned length , unsigned number) {

	for (int i = 0; i < length; i++)
	{
		if (array[i] > number) {
			std::cout << i;
			return;
		}
	}

}

int main() {

	int* array = new int[7];

	for (unsigned i = 0; i < 7; i++)
	{
		std::cin >> array[i];
	}

	int n;
	std::cin >> n;
	returnIndexOfPlace(array, 7, n);

}
