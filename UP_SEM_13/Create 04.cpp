#include<iostream>

int findPeakPlace(unsigned* mountainArr, unsigned length, unsigned peak) {


	for (unsigned i = 0; i < length; i++)
	{
		
		bool rightfulPlace = true;

		for (unsigned currPeakPlace = 0; currPeakPlace < i; currPeakPlace++)
		{
			if (mountainArr[currPeakPlace] > peak) { rightfulPlace = false;  break; }
		}

		for (unsigned currPeakPlace = i; currPeakPlace < length; currPeakPlace++)
		{
			if (mountainArr[i] < mountainArr[currPeakPlace]) { rightfulPlace = false;  break; }
		}

		if (rightfulPlace) {
			return i-1;
		}

	}


	
	return -1;
}


int main() {

	unsigned* mountainArr = new unsigned[7]{ 39, 4, 6, 1, 2, 66, 33 };

	unsigned peak;
	std::cin >> peak;

	std::cout << findPeakPlace(mountainArr, 7, peak);

}
