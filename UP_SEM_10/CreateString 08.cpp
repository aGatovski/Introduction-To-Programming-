
#include <iostream>
using namespace std;
const unsigned MAX_SIZE = 1000;

/*
5. Да се напише функция, която приема стринг и 3 символа x, a и b и замества всяко нечетно срещане на x с a, а всяко нечетно - с b.
*/
void printString(char* input) {


	while (*input)
	{
		cout << *input;
		input ++ ;
	}
}

unsigned getLength(char* input)
{
	int length = 0;

	while (input[length]) {
		length++;
	}

	return length;
}

unsigned charToInt(char a) {

	return a - '0';
}

char intToChar(unsigned number) {


	return '0' + number;
}

char* numberOcurences(char* input) {

	char* result = new char[MAX_SIZE];
	unsigned digits [10];

	

	unsigned length = getLength(input);

	for (unsigned i = 0; i < length ; i++)
	{
		digits[ charToInt(input[i]) ]++;

	}

	unsigned j = 0;

	for (unsigned i = 0; i < 10; i++)
	{
		if (digits[i] > 0) {

			result[j++] =  intToChar(digits[i]);
			result[j++] = 'x';
			result[j++] = intToChar(i);
			result[j ++] = ',';
		} 
	}

	result[j] = '\0';
	
	
	return result;
}



int main() {

	char* input = new char[MAX_SIZE];
	cin.getline(input, 30);
	char* result = numberOcurences(input);
	printString(result);
	
	delete[] input;
	delete[] result;

}
