#include <iostream>
using namespace std;

bool isPalindrom(int* arr, int startIndex, int endIndex) {

	for (int i = startIndex; i <= endIndex/2; i++)
	{
		if (arr[i] != arr[endIndex - i - 1]) {
			return false;
		}
	}
	return true;
}

bool isConcat2Palindroms(int* arr, int length) {
	for (unsigned i = 2; i < length; i++)
	{
		if (isPalindrom(arr, 0, i)) {
			if (isPalindrom(arr, i + 1, length - 1)) {
				return true;
			}
			else return false;
		}
	}
	return false;
}

int main() {
	int length;
	cin >> length;
	int arr[1000];
	for (int i = 0; i < length; i++)
	{
		cin >> arr[i];
	}
	cout << isConcat2Palindroms(arr, length);
}
