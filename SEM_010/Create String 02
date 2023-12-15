#include <iostream>
using namespace std;

bool isSmallLetter(char a) {
	
	return a >= 'a' && a <= 'z';

}

void onlySmallLetters(char string[], char finalString[]){

	int i = 0;
	int j = 0;
	while (string[i]!='\0')
	{
		if (isSmallLetter( string[i] ) ) {
			finalString[j] = string[i];
			j++;
		}
		i++;
	}
}

int main() {
	char  string [1024] ;
	char finalString[1024] = {};
	cin.getline(string, 1024);
	onlySmallLetters(string, finalString);
	cout << finalString;
}
