
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

void changeString(char* input, char x, char a, char b) {

	unsigned xOcurences = 0;

	unsigned length = getLength(input);

	for (unsigned i = 0; i < length; i++)
	{
		if (input[i] == x && xOcurences%2!=0) {
			input[i] = a;
			xOcurences++;
		}

		else if(input[i] == x && xOcurences % 2 == 0) {
			input[i] = b;
			xOcurences++;
		}
		cout << input[i];
	}



}



int main() {

	char* input1= new char[MAX_SIZE];
	
	char x, a, b;

	cin.getline(input1,30);
	cin >> x>> a>> b;

	changeString(input1, x, a, b);

	delete[] input1;

}
