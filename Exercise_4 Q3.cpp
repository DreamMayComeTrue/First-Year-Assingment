#include <iostream>

using namespace std;

void SwapFunction(int *ptrX, int *ptrY);

void SwapFunction(int *ptrX, int *ptrY){
    int temp = *ptrX;
    *ptrX = *ptrY;
    *ptrY = temp;

}

int main() {
    int x,y;;
    x = 5;
    y = 10;
    cout << "Before Swapping : " << "x = " << x << " y = " << y << endl;
    int *ptrX = &x;
    int *ptrY = &y;
    SwapFunction(ptrX,ptrY);
    cout << "After Swapping : " << "x = " << x << " y = " << y << endl;
    return 0;
}