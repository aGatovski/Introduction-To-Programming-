
#include <iostream>
using namespace std;
const unsigned MAX_SIZE = 1000;

/*
3. Да се напише функция, която приема стринг
и 2 цели числа beg и end и връща подстринг на въведения от индекс beg до индекс e
nd.Ако end е повече от дължината на стринга, връщаме стринга до края.Ако beg > дължинат
а, връщаме празен стринг.

*/

unsigned getLength(char* input)
{
	int length = 0;

	while (input[length]) {
		length++;
	}

	return length;
}


void printInput(char* input, unsigned beg, unsigned end)
{
	unsigned length = getLength(input);

	if (beg >= length) {
		cout << "Incorrect input!";
		return;
	}

	if (end >= length-1) {
		end = length-1;
	}

	for (unsigned i = beg; i <= end; i++)
	{
		cout << input[i]<<endl;
	}


}


int main() {

	unsigned beg, end;

	char* input= new char[MAX_SIZE];

	cin.getline(input,30);
	cin >> beg >> end;

	printInput(input, beg, end);
	delete[] input;
}
