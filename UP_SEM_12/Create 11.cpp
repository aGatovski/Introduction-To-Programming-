#include<iostream>

void insertionSort(int* array, int length) {

	for (size_t i = 1; i < length; i++)
	{
		int temp = array[i];
		int j = i - 1;

		while (j>=0 && array[j]>temp)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
}

int* combineArrays(int* firstArr, int* secondArr, int length) {

	
	int* combinedArr = new int[length * 2];

	for (size_t i = 0,j= 0; i < length; i++,j+=2)
	{
		combinedArr[j] = firstArr[i];
		combinedArr[j+1] = secondArr[i];
	}

	insertionSort(combinedArr,length*2);
	return combinedArr;
}

int main() {
	int length;
	std::cin >> length;

	int* firstArr = new int[length];
	int* secondArr = new int[length];

	for (size_t i = 0; i < length; i++)
	{
		std::cin >> firstArr[i];
	}

	for (size_t i = 0; i < length; i++)
	{
		std::cin >> secondArr[i];
	}

	insertionSort(firstArr, length);
	insertionSort(secondArr, length);

	int* combinedArr = combineArrays(firstArr, secondArr, length);
	int combinedL = length * 2;
	for (size_t i = 0; i < combinedL; i++)
	{
		std::cout << combinedArr[i] << " ";
	}


	delete[] firstArr;
	delete[] secondArr;
	delete[]combinedArr;
}
