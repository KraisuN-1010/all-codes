#include<bits/stdc++.h>
using namespace std;

//Check if bit is set 
bool checkSet (int num, int bitPos) {
    return num & (1 << bitPos);
}

//Set a bit
int setBit (int num, int bitPos) {
    return num | (1 << bitPos);
}

//Clear bit
int clearBit(int num, int bitPos) {
    return num & (~(1 << bitPos));
}

//Toggle bit
int toggleBit (int num, int bitPos) {
    return num ^ (1 << bitPos);
}

//Clear first set bit 
int clearFirstSet (int num) {
    return num & (num - 1);
} 

//check for power of two
bool checkPowerOf2(int number) {
     return ((number & (number - 1)) == 0);
}

//count number of set bits 
int countSetBits (int number) {
    int counter =  0;

    while (number > 0) {
        number = number & (number - 1);
        counter++;
    }

    return counter;
}

int main(){
    int num1 = 45;
    int num2 = 54;

    cout << "Before swapping :" << endl << "Num1 = " << num1 <<  " Num 2 = " << num2 << endl;

    //Swapping 
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;

    cout << "After swapping :" << endl << "Num1 = " << num1 <<  " Num 2 = " << num2 << endl << endl;

    //Bit set or not checking 
    cout << (checkSet(13, 1) ? "TRUE" : "FALSE") << endl;

    //Set a Bit
    int setNumber = setBit(9, 2);
    cout << "\nNumber after setting bit 2 in 9: " << setNumber << endl;

    //Clear a Bit
    int clearBitResult = clearBit(13, 2);
    cout << "\nNumber after clearing bit 2 in 13: " << clearBitResult << endl;

    //Toggle Bit
    int toggleBitResult = toggleBit(13, 2);
    cout << "\nNumber after toggling bit 2 in 13: " << toggleBitResult << endl;

    //Clear first set bit 
    int clearFirstSetBitResult = clearFirstSet(13);
    cout << "\nNumber after clearing first set bit in 13: " << clearFirstSetBitResult << endl;

    //check if a number is a power of 2
    cout << (checkPowerOf2(18) ? "\nTRUE" : "\nFALSE") << endl;

    //count the number of set bits
    int counterSetBits = countSetBits(15);
    cout << "Number of set bits in given number : " << counterSetBits;
}