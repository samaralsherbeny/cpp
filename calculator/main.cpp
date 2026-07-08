#include<iostream>
using namespace std;

int main() {
    char op;
    int num1, num2;

    cout << "=== Calculator App ===" << endl;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operator (+, -, *, /, %): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;
    cout << endl;
    if (op == '+') {
        cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
    }
    else if (op == '-') {
        cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
    }
    else if (op == '*') {
        cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
    }
    else if (op == '/') {
        if (num2 == 0) {
            cout << "Error: Division by zero is not allowed!" << endl;
        }
        else {
            cout << "Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
        }
    }
    else if (op == '%') {
        if (num2 == 0) {
            cout << "Error: Modulo by zero!" << endl;
        }
        else {
            cout << "Result: " << num1 % num2 << endl;
        }
    }
    else {
        cout << "Error: Invalid operator!" << endl;
    }

    return 0;
}