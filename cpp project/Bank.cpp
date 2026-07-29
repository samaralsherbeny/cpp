/*******************************************************************************
 * File        : Bank.cpp
 * Author      : samar salah
 * Date        : 29/07/2026
 * Description : Implementation of the Bank class member functions.
 *******************************************************************************/

#include "Bank.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <fstream>
#include <iostream>
#include "Account.h"
using namespace std;

/*******************************************************************************
 * Function    : addAccount
 * Description : Adds an account shared pointer to the bank's collection.
 *
 * Parameters  :
 *   acc - Shared pointer to the Account instance.
 *
 * Returns     : void
 *******************************************************************************/
void Bank::addAccount(shared_ptr<Account> acc) {
    accounts.push_back(acc);
}

/*******************************************************************************
 * Function    : findAccount
 * Description : Searches the account list for an account matching the target ID.
 *
 * Parameters  :
 *   id - Unique identifier of the target account.
 *
 * Returns     : shared_ptr<Account> - Pointer to account if found, or nullptr.
 *******************************************************************************/
shared_ptr<Account> Bank::findAccount(int id) {
    for (auto acc : accounts) {
        if (acc->getId() == id)
            return acc;
    }
    return nullptr;
}

/*******************************************************************************
 * Function    : deposit
 * Description : Deposits an amount into an account specified by ID. Throws a
 *               runtime_error if the account does not exist.
 *
 * Parameters  :
 *   id     - Account identifier.
 *   amount - Deposit amount.
 *
 * Returns     : void
 *******************************************************************************/
void Bank::deposit(int id, double amount) {
    auto acc = findAccount(id);
    if (!acc) throw runtime_error("Account not found");
    acc->deposit(amount);
}

/*******************************************************************************
 * Function    : withdraw
 * Description : Withdraws an amount from an account specified by ID. Throws a
 *               runtime_error if the account does not exist.
 *
 * Parameters  :
 *   id     - Account identifier.
 *   amount - Withdrawal amount.
 *
 * Returns     : void
 *******************************************************************************/
void Bank::withdraw(int id, double amount) {
    auto acc = findAccount(id);
    if (!acc) throw runtime_error("Account not found");
    acc->withdraw(amount);
}

/*******************************************************************************
 * Function    : transfer
 * Description : Transfers funds between two accounts. Validates account
 *               existence and ensures source and destination IDs differ.
 *
 * Parameters  :
 *   from   - Source account ID.
 *   to     - Destination account ID.
 *   amount - Transfer amount.
 *
 * Returns     : void
 *******************************************************************************/
void Bank::transfer(int from, int to, double amount) {
    if (from == to)
        throw invalid_argument("Same account");

    auto a = findAccount(from);
    auto b = findAccount(to);

    if (!a || !b)
        throw runtime_error("Account not found");

    a->withdraw(amount);
    b->deposit(amount);
}

/*******************************************************************************
 * Function    : showAccounts
 * Description : Prints details (ID, Name, Type, Balance) for all bank accounts
 *               to standard output.
 *
 * Parameters  : None.
 *
 * Returns     : void
 *******************************************************************************/
void Bank::showAccounts() {
    for (auto acc : accounts) {
        cout << acc->getId() << " "
            << acc->getName() << " "
            << acc->getType() << " "
            << acc->getBalance() << endl;
    }
}

/*******************************************************************************
 * Function    : saveToFile
 * Description : Writes account records to "data.txt" in comma-separated format.
 *
 * Parameters  : None.
 *
 * Returns     : void
 *******************************************************************************/
void Bank::saveToFile() {
    ofstream file("data.txt");

    for (auto acc : accounts) {
        file << acc->getType() << "," << acc->save() << endl;
    }
}
bool Bank::idExists(int id) {
    for (auto acc : accounts) {
        if (acc->getId() == id)
            return true;
    }
    return false;
}

/*******************************************************************************
 * Function    : loadFromFile
 * Description : Reads comma-separated account records from "data.txt" and
 *               reconstructs SavingsAccount and CheckingAccount instances.
 *
 * Parameters  : None.
 *
 * Returns     : void
 *******************************************************************************/
void Bank::loadFromFile() {
    ifstream file("data.txt");

    string type, name;
    int id;
    double balance;
    char comma;

    while (file >> type >> comma >> id >> comma >> name >> comma >> balance) {

        if (type == "Savings")
            addAccount(make_shared<SavingsAccount>(id, name, balance));
        else
            addAccount(make_shared<CheckingAccount>(id, name, balance));
    }
}
