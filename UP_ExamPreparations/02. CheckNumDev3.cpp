#include <iostream>

unsigned getNumLength(long n) {
	unsigned length = 0;

	while (n != 0) {

		length++;
		n /= 10;
	}

	return length;
}

bool isDivisibleByThree(const long n) {

	return n == (n / 3) * 3;

}

int checkNum(long n) {
	if (n < 0) {
		n *= -1;
	}

	unsigned length = getNumLength(n);

	if (length < 2) {
		return -1;
	}

	unsigned* numberArr = new unsigned[length];

	for (int i = length-1; i >=0 ; i--)
	{
		numberArr[i] = n % 10;
		n /= 10;
	}

	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			if (j != i) {
				n = n * 10 + numberArr[j];
			}

		}

		if (isDivisibleByThree(n)) {
			return i+1;
		}

		else {
			n = 0;
		}
	}

	return 0;
}

int main() {

	long n;
	std::cin >> n;
	
	std::cout << checkNum(n);

	

}
