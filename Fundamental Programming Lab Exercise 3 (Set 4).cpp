#include <iostream>
#include <string>
using namespace std;

int main() {
    int number, sum = 1, digit;
    
    cout << "Enter an integer number: ";
    cin >> number;

    int Temp = number;  


    do {
        digit = Temp % 10;  
        sum *= digit;       
        Temp /= 10;         
    } while (Temp != 0);    


    cout << "Sum of digits = " << sum << endl;

    if (sum % 2 == 0) {
        cout << sum << " is even number";
    } else {
        cout << sum << " is odd number";
    }

    bool flag = false;

    if (sum % 3 == 0) {
        cout << " and multiples of";
        cout << " 3";
        flag = true;
    }
    if (sum % 5 == 0) {
        cout << " and multiples of";
        cout << (flag ? " and" : "") << " 5";
    }

    return 0;
}

