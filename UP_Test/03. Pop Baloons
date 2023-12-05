#include <iostream>
using namespace std;
const int   MAX_SIZE = 255;

void initialiseArray(char* arr, int length) {

    for (int i = 0; i < length; i++)
    {
        char a;
        cin >> a;
        arr[i] = a;
    }
}

void printArray(char* arr, int n) {

    for (int i = 0; i < n; i++) {

        cout << arr[i] << " ";
        
    }
    cout << endl;
}

void addSphere(char* arr, int& length,int startIdx, int elementToAdd) {
    for (int i = length-1; i > startIdx; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[startIdx+1] = elementToAdd;
    length++;
}

int findSequence(char* arr, int length, int& startIdx) {
    int counter = 1;
    //forward finding
    for (int i = startIdx; i < length; i++)
    {
        if (arr[i] == arr[i + 1]) {
            counter++;
        }
        else break;
    }

    //back finding
    for (int j = startIdx; j >= 0; j--)
    {
        if (arr[j] == arr[j - 1]) {
            counter++;
        }
        else {
            //startIdx =  index of sequence's start
            startIdx =j;
            break;
        }
    }
    return counter;
}

void popSpheres(char* arr, int& length, int startIdx, int sequence) {

    if (startIdx < 0 || startIdx >= length) {
        std::cout << "Invalid startIndex to pop." << std::endl;
        return;
    }

    for (int i = startIdx; i < length; i++) {
        if (i + sequence == length) break;
         arr[i] = arr[i + sequence];
        
    }
    length -= sequence;
}

int main()
{
    int n;
    cin >> n;
    char colorSpheres[MAX_SIZE];

    if (n <= 0 || n >= 256) {
        cout << "Incorrect input";
        return 0;
    }

    initialiseArray(colorSpheres, n);

    int shots;
    cin >> shots;

    if (shots < 0 || shots>127) {
        cout << "Incorrect input";
        return 0;
    }

    while(shots!=0){
        int idx;
        char sphere;
        cin >> idx>> sphere;

        //c is [a-z]
        if (sphere < 97 || sphere>122) {
            cout << "Incorrect input";
            return 0;
        }

        //При невалиден индекс, изстреляното топче изчезва.
        if (idx<0 || idx>n) {
       
            shots--;
            continue;
        }

        addSphere(colorSpheres, n, idx, sphere);
       
       
        int seq = findSequence(colorSpheres, n, ++idx);
       
        while (seq>=3) {
            
            popSpheres(colorSpheres, n, idx, seq);
           
            seq = findSequence(colorSpheres, n, idx);
        }
        shots--;

       
    }

    if (n == 0) {
        cout << "-1";
        return 0;
    }

    else  printArray(colorSpheres, n);

}
