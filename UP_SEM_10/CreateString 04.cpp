
#include <iostream>
using namespace std;
const unsigned MAX_SIZE = 1000;

/*
 4. Да се напише функция, която приема 2 стринга и сравнява лексикографски - връща -1, ако първият е по-малък, 0, ако са равни и 1, ако първият е по-голям.
*/

unsigned getLength(char* input)
{
	int length = 0;

	while (input[length]) {
		length++;
	}

	return length;
}


int lexigographycalCheck(char* input1, char* input2) {

	unsigned length1 = getLength(input1);
	unsigned length2 = getLength(input2);

	for (size_t i = 0; i < length1; i++)
	{
		if (input1[i] < input2[i]) {
			return -1;
		}

		else if (input1[i] > input2[i]) {
			return 1;
		}
	}

	if (length1 == length2) {
		return 0;
	}

	else if (length1 > length2) {
		return 1;
	}

	else return -1;


}


int main() {

	char* input1= new char[MAX_SIZE];
	char* input2 = new char[MAX_SIZE];

	cin.getline(input1,30);
	cin.getline(input2, 30);
	cout << lexigographycalCheck(input1, input2);

	delete[] input1;
	delete[] input2;
}
