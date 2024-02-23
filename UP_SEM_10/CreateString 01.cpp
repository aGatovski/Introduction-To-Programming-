#include <iostream>
using namespace std;

int findCountRepetitions(char string[], char repeatedCharachter) {
	unsigned i = 0;
	unsigned count = 0;
	while (string[i] != '\0') {
		if (string[i] == repeatedCharachter) {
			count++;
		}
		i++;
	}
	return count;
}

int main() {
	char  string [1024] = "aabbabc";
	char repeatedCharachter;
	cin >> repeatedCharachter;
	cout << findCountRepetitions(string, repeatedCharachter);
}
