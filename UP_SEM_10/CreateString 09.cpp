#include <iostream>


bool containsChar(const char* str, char elementToFind) {

	while (*str) {
		
		if (*str == elementToFind) {
			return true;
		}
		str++;

	}
	return false;

}

void onlyDifferentChars(char* array1, char* array2, char* result) {

	unsigned currentResultIdx = 0;
	char* holdArray1 = array1;
	char* holdArray2 = array2;

	while (*holdArray1) {
		
		if (!containsChar(array2, *holdArray1)) {
			result[currentResultIdx] = *holdArray1;

				currentResultIdx++;
		}

		if (!containsChar(array1, *holdArray2)) {
			result[currentResultIdx] = *holdArray2;

			currentResultIdx++;
		}

		holdArray1++;
		holdArray2++;
	}
	
	for (size_t i = 0; i < currentResultIdx; i++)
	{
		std::cout << result[i];
	}
	
}

int main() {

	unsigned length;
	std::cin >> length;

	char* array1 = new char[length+1];
	std::cin >> array1;

	char* array2 = new char[length+1];
	std::cin >> array2;

	char* result = new char[length +1];

	onlyDifferentChars(array1, array2, result);

	delete[] array1;
	delete[] array2;
	delete[] result;
}
