#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int NumRows, NumColumns;
    cout << "Enter the number of rows: ";
    cin >> NumRows;
    cout << "Enter the number of columns: ";
    cin >> NumColumns;

    
    int **matrix = new int*[NumRows];
    for (int i = 0; i < NumRows; i++) {
        matrix[i] = new int[NumColumns];
    }

    srand(time(0)); 

    
    for (int i = 0; i < NumRows; i++) {
        for (int j = 0; j < NumColumns; j++) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }

    cout << '\n';
    cout << "Matrix:" << endl;
    for (int i = 0; i < NumRows; i++) {
        for (int j = 0; j < NumColumns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << '\n';
    cout << "Sum of each row:" << endl;
    for (int i = 0; i < NumRows; i++) {
        int rowSum = 0;
        for (int j = 0; j < NumColumns; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Row " << i + 1 << ": " << rowSum << endl;
    }

    cout << '\n';
    cout << "Sum of each column:" << endl;
    for (int j = 0; j < NumColumns; j++) {
        int colSum = 0;
        for (int i = 0; i < NumRows; i++) {
            colSum += matrix[i][j];
        }
        cout << "Column " << j + 1 << ": " << colSum << endl;
    }

    
    for (int i = 0; i < NumRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}