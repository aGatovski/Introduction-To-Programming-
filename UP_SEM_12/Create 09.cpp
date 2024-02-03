#include<iostream>

void generateSubarrays(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            std::cout << "[";
            for (int k = i; k <= j; ++k) {
                std::cout << arr[k];
                if (k < j) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
        }
    }
}


int main() {
	unsigned length = 3;
	int* array = new int[length] {1, 2, 3};

    generateSubarrays(array, length);
}
