#include <iostream>
#include <string>
using namespace std;

int main() {
    int number, sum = 1, digit;
    
    cout << "Enter an integer number: ";
    cin >> number;

    int Temp = number;  


    while (Temp != 0) {
        digit = Temp % 10;  
        sum *= digit;       
        Temp /= 10;         
    }    


    cout << "Sum of digits = " << sum << endl;
    cout << sum << " is a multiple of";
    bool flag = false;

    if (sum % 4 == 0) {
        cout << " 4";
        flag = true;
    }
    if (sum % 5 == 0) {
        cout << (flag ? " and" : "") << " 5";
        flag = true;
    }
    if (sum % 7 == 0) {
        cout << (flag ? " and" : "") << " 7";
    }

    return 0;
}

