#include<iostream>

void sortArray(int* array, unsigned length, int n) {

	int* sortedArray = new int[length];
	int currIdx = 0;

	for (int i = 0; i < length; i++)
	{
		if (array[i] < n) {
			sortedArray[currIdx] = array[i];currIdx++;

		}
	}

	sortedArray[currIdx] =3; currIdx++;


	for (int i = 0; i < length; i++)
	{
		if (array[i] > n) {
			sortedArray[currIdx] = array[i];
			currIdx++;
		}
	}


	for (size_t i = 0; i < length; i++)
	{
		std::cout << sortedArray[i] << " ";
	}
}

int main() {

	int* array = new int[9] { 1, 5, 6, 3, 0, -1, 2, 9, 7 };
	int n = 3;

	sortArray(array, 9, n);
}
