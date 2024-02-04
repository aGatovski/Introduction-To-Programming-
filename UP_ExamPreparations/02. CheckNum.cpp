#include <iostream>

void swap(int& a, int& b) {
	int c = b;
	b = a;
	a = c;
}

unsigned numberLength(long N) {

	unsigned length = 0;
	while (N != 0)
	{
		N /= 10;
		length++;
	}

	return length;

}

int checkNum(long n, unsigned m, unsigned l) {

	unsigned numbLen = numberLength(n);
	unsigned length = numbLen;
	if (m > numbLen || l > numbLen) {
		return -1;
	}

	int* array = new int[numbLen];
	
	while (n != 0)
	{
		array[numbLen - 1] = n - ((n / 10) * 10);
	
		n /= 10;
		numbLen--;
	}


	swap(array[m], array[l]);



	for (size_t i = 0; i < length; i++)
	{
		n = (n * 10) + array[i];

	}
	delete[] array;
	int mask = 3;

	return (n & mask) == 0;

}


int main() {

	long N;
	std::cin >> N;

	unsigned m, l;
	std::cin >> m >> l;

	std::cout << checkNum(N, m, l);




}
