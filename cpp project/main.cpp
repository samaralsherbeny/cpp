/*******************************************************************************
 * File        : main.cpp
 * Author      : samar salah
 * Date        : 29/07/2026
 * Description : Entry point for the Simple Bank System CLI application.
 *               Handles menu navigation, input validation, string normalization,
 *               and structured exception handling for bank operations.
 *******************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include "Bank.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "Exceptions.h"

using namespace std;

/*******************************************************************************
 * Function    : main
 * Description : Main entry point of the application. Manages the primary user 
 *               interface loop, parses input, dispatches commands to the Bank 
 *               instance, and safely catches targeted domain exceptions.
 * 
 * Parameters  : None.
 * 
 * Returns     : int - Program exit status code (0 for successful completion).
 *******************************************************************************/
int main() {
    Bank bank;
    bank.loadFromFile();

    int choice;

    do {
        cout << "\n=============================\n";
        cout << "     SIMPLE BANK SYSTEM\n";
        cout << "=============================\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer\n";
        cout << "5. Show Accounts\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        //  Input validation
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << " Invalid input!\n";
            continue;
        }

        try {
            // ================= CREATE =================
            if (choice == 1) {
                int id;
                string name, type;
                double balance;

                cout << "Enter ID: ";
                cin >> id;

                cout << "Enter Name: ";
                getline(cin >> ws, name);

                cout << "Enter Balance: ";
                cin >> balance;

                cout << "Enter Type (Savings / Checking): ";
                cin >> type;

                //  normalize input
                transform(type.begin(), type.end(), type.begin(), ::tolower);

                if (type == "savings") {
                    bank.addAccount(make_shared<SavingsAccount>(id, name, balance));
                }
                else if (type == "checking") {
                    bank.addAccount(make_shared<CheckingAccount>(id, name, balance));
                }
                else {
                    throw runtime_error("Invalid account type!");
                }

                cout << " Account created successfully!\n";
            }

            // ================= DEPOSIT =================
            else if (choice == 2) {
                int id;
                double amount;

                cout << "Enter Account ID: ";
                cin >> id;

                cout << "Enter Amount to deposit: ";
                cin >> amount;

                bank.deposit(id, amount);

                cout << " Deposit successful!\n";
            }

            // ================= WITHDRAW =================
            else if (choice == 3) {
                int id;
                double amount;

                cout << "Enter Account ID: ";
                cin >> id;

                cout << "Enter Amount to withdraw: ";
                cin >> amount;

                bank.withdraw(id, amount);

                cout << " Withdraw successful!\n";
            }

            // ================= TRANSFER =================
            else if (choice == 4) {
                int from, to;
                double amount;

                cout << "Enter From Account ID: ";
                cin >> from;

                cout << "Enter To Account ID: ";
                cin >> to;

                cout << "Enter Amount: ";
                cin >> amount;

                bank.transfer(from, to, amount);

                cout << " Transfer successful!\n";
            }

            // ================= SHOW =================
            else if (choice == 5) {
                cout << "\n--- All Accounts ---\n";
                bank.showAccounts();
            }

            // ================= EXIT =================
            else if (choice == 0) {
                cout << "Saving data...\n";
                bank.saveToFile();
                cout << "Goodbye!\n";
            }

            else {
                cout << " Invalid choice, try again.\n";
            }
        }

        //  Specific exception first
        catch (const InsufficientBalanceException& e) {
            cout << " Insufficient Balance: " << e.what() << endl;
        }

        //  General exception
        catch (const exception& e) {
            cout << " Error: " << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}
