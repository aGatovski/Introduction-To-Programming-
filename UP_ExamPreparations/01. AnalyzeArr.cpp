#include <iostream>

const unsigned MAX = 100;

int getLength(char* input) {

	if (!input) {
		return -1;
	}

	unsigned length = 0;
	while (input[length]) {
		length++;
	}

	return length;
}

unsigned containsCharNTimes(char* input, char ch) {

	unsigned charOcc = 0;

	while (*input)
	{
		if(*input==ch){
			charOcc++;
		}
		input++;
	}

	

	return charOcc;
	
}

int analyzeArr(char* input) {

	unsigned uniqueElements = 0;
	unsigned length = getLength(input);

	if (!input) {
		return -1;
	}


	for (size_t i = 0; i < length; i++)
	{
		if (containsCharNTimes(input, input[i])==1) {
			uniqueElements++;
		}
	}
	return uniqueElements;
}

int main() {

	

	char* input = new char[MAX];
	std::cin >> input;

	std::cout << analyzeArr(input);
}
