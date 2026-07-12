#include<iostream>
#include<string>
using namespace std;
int main() {
    double balance = 500.0;
    int choice;
    double amount;
    for (;;) {
        cout << "\n--- ATM Menu ---" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Your balance is: $" << balance << endl;
        }
        else if (choice == 2) {
            cout << "Enter deposit amount: $";
            cin >> amount;
            balance = balance + amount;
            cout << "Deposited successfully!" << endl;
        }
        else if (choice == 3) {
            cout << "Enter withdrawal amount: $";
            cin >> amount;
            if (amount <= balance) {
                balance = balance - amount;
                cout << "Withdrawn successfully!" << endl;
            }
            else {
                cout << "Not enough money in account!" << endl;
            }
        }
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid option. Try again." << endl;
        }
    }
    return 0;
}
