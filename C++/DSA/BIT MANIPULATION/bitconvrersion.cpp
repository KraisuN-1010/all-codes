#include<bits/stdc++.h>
using namespace std;

// Function to convert decimal to binary
string decimalToBinary(int number) {
    if (number == 0) return "0";
    
    string result = "";
    while (number > 0) {
        result += (number % 2) ? '1' : '0';
        number /= 2;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

// Function to convert binary to decimal
int binaryToDecimal(string binary) {
    // Validate input
    for (char c : binary) {
        if (c != '0' && c != '1') {
            cout << "Invalid binary string! Only 0 and 1 are allowed." << endl;
            return -1;
        }
    }
    
    if (binary.empty()) {
        cout << "Empty binary string!" << endl;
        return -1;
    }
    
    int decimal = 0;
    // Process from left to right using bit shifting method
    for (char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }
    
    return decimal;
}

// Function to display menu and get user choice
int getChoice() {
    int choice;
    cout << "\n=== Binary-Decimal Converter ===" << endl;
    cout << "1. Convert Decimal to Binary" << endl;
    cout << "2. Convert Binary to Decimal" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    return choice;
}

// Function to handle decimal to binary conversion
void handleDecimalToBinary() {
    int number;
    cout << "\nEnter a decimal number: ";
    cin >> number;
    
    if (number < 0) {
        cout << "Please enter a non-negative number." << endl;
        return;
    }
    
    string binary = decimalToBinary(number);
    cout << "Decimal " << number << " in binary: " << binary << endl;
    
    // Verification - convert back to decimal
    int verification = binaryToDecimal(binary);
    cout << "Verification: " << binary << " back to decimal = " << verification << endl;
}

// Function to handle binary to decimal conversion
void handleBinaryToDecimal() {
    string binary;
    cout << "\nEnter a binary number: ";
    cin >> binary;
    
    int decimal = binaryToDecimal(binary);
    
    if (decimal != -1) {
        cout << "Binary " << binary << " in decimal: " << decimal << endl;
        
        // Verification - convert back to binary
        string verification = decimalToBinary(decimal);
        cout << "Verification: " << decimal << " back to binary = " << verification << endl;
    }
}

int main() {
    cout << "Welcome to Binary-Decimal Converter!" << endl;
    
    while (true) {
        int choice = getChoice();
        
        switch (choice) {
            case 1:
                handleDecimalToBinary();
                break;
                
            case 2:
                handleBinaryToDecimal();
                break;
                
            case 3:
                cout << "\nThank you for using the converter!" << endl;
                return 0;
                
            default:
                cout << "\nInvalid choice! Please enter 1, 2, or 3." << endl;
                break;
        }
        
        // Ask if user wants to continue
        char continueChoice;
        cout << "\nDo you want to perform another conversion? (y/n): ";
        cin >> continueChoice;
        if (continueChoice != 'y' && continueChoice != 'Y') {
            cout << "Thank you for using the converter!" << endl;
            break;
        }
    }
    return 0;
}