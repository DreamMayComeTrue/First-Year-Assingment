#include <iostream>

using namespace std;

int main() {
    int Integer;
    int *IntegerPtr = &Integer;
    Integer = 42;
    cout << "Value of the integer : " << *IntegerPtr << endl;
    cout << "Address of the integer : " << IntegerPtr << endl;
    return 0;
}