#include<iostream>

void f(int a) {
	std::cout << a;
}

unsigned getLength(char* input) {

	if (!input) {
		return 0;
	}
	unsigned length = 0;

	while (input[length]) {
		length++;
	}
	return length;
}

int findSmallestLength(int a, int b, int c) {

	int smallest = 100;
	if (a < smallest) smallest = a;
	if (b < smallest) smallest = b;
	if (c < smallest) smallest = c;
	return smallest;
}

char* findLongestPrefix(char* first, char* second, char* third) {

	unsigned fLength = getLength(first), sLength = getLength(second), tLength = getLength(third);
	unsigned smallestLength = findSmallestLength(fLength, sLength, tLength);

	unsigned prefIDx = 0;
	char* pref = new char[smallestLength + 1];

	if (!first || !second || !third) {
		return pref;
	}

	for (size_t i = 0; i < smallestLength; i++)
	{
		if (first[i] == second[i] && second[i] == third[i]) {
			pref[prefIDx++] = first[i];

		}
		else {
			pref[prefIDx] = '\0';
			return pref;
		}
	}
	pref[prefIDx] = '\0';
	return pref;
}


int main() {
	
	char* firstString = new char[10];
	char* secondString = new char[10];
	char* thirdString = new char[10];


	std::cin >> firstString >> secondString >> thirdString;
	char* pref = findLongestPrefix(firstString, secondString, thirdString);

	int prefL = getLength(pref);

	for (size_t i = 0; i < prefL; i++)
	{
		std::cout << pref[i];
	}

}
