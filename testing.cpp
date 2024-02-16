#include <iostream>
using namespace std;
/*
this file is used for testing functions or theories in mind.
*/

int main(){
    int x = 10;
    int* pX = &x;
    cout << "Before changing: " << *pX << endl;
    // after changing pX
    *pX = 20;
    cout << "After changing: " << *pX;
    return 0;
}