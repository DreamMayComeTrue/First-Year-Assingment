#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

int main() {
    int SizeArray;
    cout << "Enter the size of the array: ";
    cin >> SizeArray;
    int *Array = new int[SizeArray]; 

    srand(time(0)); 

    
    for (int i = 0; i < SizeArray; i++) {
        Array[i] = rand(); 
    }

    
    for (int i = 0; i < SizeArray; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;

    delete[] Array; 
    return 0;
}