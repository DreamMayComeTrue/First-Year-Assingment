#include <iostream>
using namespace std;

int main() {
    int number, sum = 0, digit;
    
    cout << "Enter an integer number: ";
    cin >> number;
    
    int Temp = number;

    while (Temp != 0) {
        digit = Temp % 10;  
        sum += digit;       
        Temp /= 10;         
    }

    cout << "Sum of digits = " << sum << endl;

    if (sum % 2 == 0) {
        cout << sum << " is even number";
    } else {
        cout << sum << " is odd number";
    }

    bool flag = false;

    if (sum % 4 == 0) {
        cout << " and multiples of";
        cout << " 4";
        flag = true;
    }
    if (sum % 5 == 0) {
        cout << " and multiples of";
        cout << (flag ? " and" : "") << " 5";
    }

    cout << endl;
    return 0;
}
