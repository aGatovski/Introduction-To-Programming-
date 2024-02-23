
#include <iostream>
using namespace std;
const unsigned MAX_SIZE = 1000;

/*
5. Да се напише функция, която приема стринг и 3 символа x, a и b и замества всяко нечетно срещане на x с a, а всяко нечетно - с b.
*/

unsigned getLength(char* input)
{
	int length = 0;

	while (input[length]) {
		length++;
	}

	return length;
}

char* changeString(char* input1, char* input2, char* input3) {

	char* result = new char[MAX_SIZE];
	int i = 0;

	while ((*input1 == *input2) && (*input1 == *input3))
	{
		result[i] = *input1;
		i++;
		input1++;
		input2++;
		input3++;
	
	
	}

	result[i] = '\0';
	return result;


}



int main() {

	char* input1= new char[MAX_SIZE];

	char* input2 = new char[MAX_SIZE];



	char* input3 = new char[MAX_SIZE];
	char x, a, b;

	cin.getline(input1,30);
	cin.getline(input2, 30);

	cin.getline(input3, 30);

	char* result = changeString(input1, input2, input3);

	while (*result) {
		cout << *result;
		result++;
	}
	

	delete[] input1;
	delete[] input2;
	delete[] input3;
}
