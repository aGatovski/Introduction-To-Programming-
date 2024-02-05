#include<iostream>
const unsigned max = 100;

unsigned getLength(char* text) {

	if (!text) {
		return 0;
	}

	unsigned length = 0;

	while (text[length])
	{
		length++;
	}

	return length;
}

bool isValidString(char* text) {

	if (!text) {
		return false;
	}

	while (*text)
	{
		if (*text < 32 || *text>126) {
			return false;
		}

		text++;
	}
	return true;
}

char* encodeWord(char* input, int n) {

	unsigned length = getLength(input);
	char* output = new char[length + 1];

	for (size_t i = 0; i < length; i++)
	{
		if (input[i] + n > 126) {
			output[i] = 126;
		}

		else {
			output[i] = input[i] + n;
		}
		
	}

	return output;
}


int main() {

	char* input = new char[max];
	char* output;
	unsigned n,length;

	std::cin >> n;

	if (n < 2 || n>49) {
		std::cout << "Incorrect input";
		return 0;
	}

	std::cin >> input;

	length = getLength(input);

	if (!isValidString(input)) {

		std::cout << "Incorrect input";
		return 0;

	}

	else {
		output = encodeWord(input, n);
	}

	for (size_t i = 0; i < length; i++)
	{
		std::cout << output[i]<< " ";
	}

	delete[] output;
	delete[] input;
}
