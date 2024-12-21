#include <iostream>
#include <string>
using namespace std;

int main() {
    int number, sum = 0, digit;
    
    cout << "Enter an integer number: ";
    cin >> number;

    int Temp = number;  


    do {
        digit = Temp % 10;  
        sum += digit;       
        Temp /= 10;         
    } while (Temp != 0);    


    cout << "Sum of digits = " << sum << endl;
    cout << sum << " is a multiple of";
    bool flag = false;

    if (sum % 3 == 0) {
        cout << " 3";
        flag = true;
    }
    if (sum % 4 == 0) {
        cout << (flag ? " and" : "") << " 4";
        flag = true;
    }
    if (sum % 5 == 0) {
        cout << (flag ? " and" : "") << " 5";
    }

    return 0;
}

