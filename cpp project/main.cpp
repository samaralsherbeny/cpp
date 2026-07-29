/*******************************************************************************
 * File        : main.cpp
 * Author      : samar salah
 * Date        : 29/07/2026
 * Description : Entry point for the Banking Management System program. Handles
 *               user interaction and menu options.
 *******************************************************************************/

#include <iostream>
#include "Bank.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

/*******************************************************************************
 * Function    : main
 * Description : Main entry point of the program. Loads saved accounts,
 *               presents a menu loop for user operations (create, deposit,
 *               withdraw, transfer, show), handles exceptions, and saves
 *               account data upon exiting.
 *
 * Parameters  : None.
 *
 * Returns     : int - Exit status code (0 for successful execution).
 *******************************************************************************/
int main() {
    Bank bank;
    bank.loadFromFile();

    int choice;

    do {
        cout << "\n1.Create\n2.Deposit\n3.Withdraw\n4.Transfer\n5.Show\n0.Exit\n";
        cin >> choice;

        try {
            if (choice == 1) {
                int id;
                string name, type;
                double balance;

                cin >> id >> name >> balance >> type;

                if (type == "Savings")
                    bank.addAccount(make_shared<SavingsAccount>(id, name, balance));
                else
                    bank.addAccount(make_shared<CheckingAccount>(id, name, balance));
            }

            else if (choice == 2) {
                int id; double amount;
                cin >> id >> amount;
                bank.deposit(id, amount);
            }

            else if (choice == 3) {
                int id; double amount;
                cin >> id >> amount;
                bank.withdraw(id, amount);
            }

            else if (choice == 4) {
                int a, b; double amount;
                cin >> a >> b >> amount;
                bank.transfer(a, b, amount);
            }

            else if (choice == 5) {
                bank.showAccounts();
            }
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 0);

    bank.saveToFile();
    return 0;
}
