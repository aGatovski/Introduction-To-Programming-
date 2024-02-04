#include <iostream>

size_t myStrLen(const char* str) {
	if (!str) {
		return 0;
	}

	size_t index = 0;
	while (str[index]) {
		index++;
	}

	return index;
}

bool isDigit(char a) {
	return a > '0' && a < '9';
}


int checkDate(const char* date) {

	if (!date) {
		return -1;
	}

	

	unsigned day=0, month=0, year;
	size_t length = myStrLen(date);

	if (length != 9 ) {
		return -1;
	}

	for (size_t i = 0; i < length; i++)
	{
		if (i != 2 && i != 5  && (!isDigit(date[i]))) {
			return -1;
		}
	}


	day = date[0] * 10 + date[1];
	month = date[3] * 10 + date[4];
	year = date[6] * 1000 + date[7] * 100 + date[8] * 10 + date[9];

	if(date[2] != '.' || date[5] != '.' ){
		return -1;
	}

	if (month > 12 || month < 1) {
		return -1;
	}

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day < 0 || day>31) {
			
				return -1;
		}
	}

	else if (month == 2) {
		if (year % 4 == 0) {

			if (day < 0 || day>29) {

				return -1;
			}

		}

		else {
			if (day < 0 || day>28) {

				return -1;
			}

		}
	}

	else {
		if (day < 0 || day>30) {

			return -1;
		}
	}


	return 1;

}


int main() {

	char* date = new char[11];

	std::cin.getline(date, 11);

	std::cout << checkDate(date);

	
	

}
