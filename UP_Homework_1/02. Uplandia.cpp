#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;
int population = 0;



void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

void initialiseArray(int* arr, int length) {

    for (int i = 0; i < length; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
}

void printArray(int* arr, int n){
    
    for (int i = 0; i < n; i++) {

        cout << arr[i] << " ";
        cout << endl;
    }
      
}

void sortArray(int* arr, int length) {
 
    for (int i = 0; i < length; i++)
    {
         int temp = arr[i];
        int j = i - 1;

        while (j>=0 && arr[j]> temp)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = temp;
    }
}



bool includesElementInArray(int* arr, int left, int right, int element) {
    
    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] == element) return true;

        if (arr[middle] < element) left = middle + 1;

        else right = middle - 1;
    }

    return false;
}


void removeElementsFromArray(int* arr, int& length ,int elementToBeRemoved, int numberOfRemoves) {
    int i = 0;
    while (numberOfRemoves != 0) {

        if (includesElementInArray(arr, 0, length, elementToBeRemoved) && length!=0)
        {
            if (arr[i] == elementToBeRemoved) {
                swap(arr[i], arr[length - 1]);
                    length--;
                    numberOfRemoves--;
                    sortArray(arr, length);
            }

            else i++;
        }
        else break;
    }
}





int main()
{
    ///n-length array
    int n;
    cin >> n;

    if (n < 1 || n>1000) {
        cout << "Incorrect input";
        return 0;
    }

    int arrayAnswers[MAX_SIZE];
    initialiseArray(arrayAnswers, n);
    

    while (n!=0) {
        population += arrayAnswers[0] + 1;
        removeElementsFromArray(arrayAnswers, n, arrayAnswers[0], arrayAnswers[0]+1);
    }
    cout << "Population is " << population;
}
