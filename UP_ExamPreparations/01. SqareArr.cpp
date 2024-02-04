#include <iostream>

void printArr(int* array, size_t len) {

	for (size_t i = 0; i < len; i++)
	{
		std::cout << array[i]<<" ";
	}

}

void insertionSort(int* array, size_t len) {

	for (size_t i = 1; i < len; i++)
	{
		int temp = array[i];
		size_t j = i - 1;

		while (j>=0 && array[j]> temp) {

			array[j + 1] = array[j];
			j--;


		}

		array[j + 1] = temp;

	}

}

void squareArr(int* array, size_t len) {

	for (size_t i = 0; i < len; i++)
	{
		array[i] = array[i] * array[i];
	}

}

int main() {

	size_t length;
	std::cin >> length;

	int* array = new int[length];

	for (size_t i = 0; i < length; i++)
	{
		std::cin >> array[i];
	}

	insertionSort(array, length);
	squareArr(array, length);
	printArr(array, length);

	delete[] array;

}
