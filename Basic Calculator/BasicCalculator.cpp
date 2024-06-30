#include <iostream>
#include <limits> // for numeric_limits
using namespace std;

// Function prototypes
double addition(double a, double b);
double subtraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);

// Function definitions
double addition(double a, double b) {
    return a + b;
}

double subtraction(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Division by zero is not allowed." << endl;
        return numeric_limits<double>::quiet_NaN(); // return NaN for invalid division
    }
}

int main() {
    char operation;
    double num1, num2;
    bool exitFlag = false;

    while (!exitFlag) {
        // Display menu
        cout << "Choose an operation:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";

        // Get user input for operation choice
        cin >> operation;

        // Validate user input for operation choice
        if (operation < '1' || operation > '5' || cin.peek() != '\n') {
            cout << "Invalid input. Please enter a single digit from 1 to 5." << endl;
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            continue; // restart the loop
        }

        // Convert char to integer for switch case
        int choice = operation - '0';

        // Handle exit option
        if (choice == 5) {
            exitFlag = true;
            cout << "Exiting the program." << endl;
            break;
        }

        // Get user input for numbers
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        // Check if inputs are valid numbers
        if (cin.fail()) {
            cout << "Invalid input. Please enter numeric values." << endl;
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            continue; // restart the loop
        }

        // Perform operation based on user choice
        switch (choice) {
            case 1:
                cout << "Result: " << addition(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << subtraction(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << multiplication(num1, num2) << endl;
                break;
            case 4:
                cout << "Result: ";
                if (num2 != 0)
                    cout << division(num1, num2) << endl;
                else
                    cout << "Division by zero is not allowed." << endl;
                // division function handles division by zero case
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
                break;
        }
    }

    return 0;
}