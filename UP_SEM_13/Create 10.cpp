#include<iostream>

void insertionSort(unsigned* array, unsigned length ) {

	for (unsigned i = 0; i < length; i++)
	{
		unsigned temp = array[i];
		int j = i - 1;

		while (j>=0 && array[j] > temp){
			array[j + 1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}


}


void printArray(unsigned* array, unsigned length) {
	
	for (unsigned i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}

}

void printGuests(unsigned* array, unsigned length) {

	unsigned* maleGuests = new unsigned[length / 2];
	unsigned* femaleGuests = new unsigned[length / 2];

	unsigned maleGuestIDX = 0;
	unsigned femaleGuestIDX = 0;

	for (unsigned i = 0; i < length; i++)
	{
		if (array[i] % 2 == 0) {
			maleGuests[maleGuestIDX] = array[i];
				maleGuestIDX++;
		}
		else {
			femaleGuests[femaleGuestIDX] = array[i];
			femaleGuestIDX++;
		}
	}

	for (int i = 0; i < length/2; i++)
	{
		std::cout << maleGuests[i] << " " << femaleGuests[i] << std::endl;
	}
	delete maleGuests;
	delete femaleGuests;
}

int main() {

	unsigned length = 14;
	unsigned* guests = new unsigned[length] {201, 186, 180, 186, 183, 185, 170, 161, 194, 197, 164, 175, 161, 186};
	insertionSort(guests, length);
	//printArray(guests, length);

	printGuests(guests, length);

}
