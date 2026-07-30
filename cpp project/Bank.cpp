/*******************************************************************************
 * File        : Bank.cpp
 * Author      : samar salah 
 * Date        : 30/07/2026
 * Description : Implementation of the Bank class member functions, including
 *               custom exception handling for account operations.
 *******************************************************************************/

#include "Bank.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <fstream>
#include <iostream>
#include "Account.h"
#include "Exceptions.h"
using namespace std;

/*******************************************************************************
 * Function    : addAccount
 * Description : Adds a new account to the bank. Throws a DuplicateIDException 
 *               if an account with the same ID already exists.
 * 
 * Parameters  : 
 *   acc - Shared pointer to the Account instance to be added.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::addAccount(shared_ptr<Account> acc) {
    if (idExists(acc->getId())) {
        throw DuplicateIDException();
    }
    accounts.push_back(acc);
}

/*******************************************************************************
 * Function    : findAccount
 * Description : Searches for an account matching the provided ID. Throws an 
 *               AccountNotFoundException if no matching account is found.
 * 
 * Parameters  : 
 *   id - Unique identifier of the target account.
 * 
 * Returns     : shared_ptr<Account> - Pointer to the matching account.
 *******************************************************************************/
shared_ptr<Account> Bank::findAccount(int id) {
    for (auto acc : accounts) {
        if (acc->getId() == id)
            return acc;
    }
    throw AccountNotFoundException();
}

/*******************************************************************************
 * Function    : deposit
 * Description : Deposits a specified amount into the account matching the ID.
 * 
 * Parameters  : 
 *   id     - Target account identifier.
 *   amount - Monetary amount to deposit.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::deposit(int id, double amount) {
    auto acc = findAccount(id);
    acc->deposit(amount);
}

/*******************************************************************************
 * Function    : withdraw
 * Description : Withdraws a specified amount from the account matching the ID.
 * 
 * Parameters  : 
 *   id     - Target account identifier.
 *   amount - Monetary amount to withdraw.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::withdraw(int id, double amount) {
    auto acc = findAccount(id);
    acc->withdraw(amount);
}

/*******************************************************************************
 * Function    : transfer
 * Description : Transfers money from one account to another. Ensures source 
 *               and destination accounts are distinct before executing.
 * 
 * Parameters  : 
 *   from   - Source account ID.
 *   to     - Destination account ID.
 *   amount - Monetary amount to transfer.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::transfer(int from, int to, double amount) {
    if (from == to)
        throw invalid_argument("Same account");

    auto a = findAccount(from);
    auto b = findAccount(to);

    a->withdraw(amount);
    b->deposit(amount);
}

/*******************************************************************************
 * Function    : showAccounts
 * Description : Displays the ID, owner name, type, and current balance for 
 *               all registered accounts.
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
 * Description : Writes all account data in comma-separated format to "data.txt".
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

/*******************************************************************************
 * Function    : idExists
 * Description : Helper method to check if an account with the given ID already 
 *               exists in the bank repository.
 * 
 * Parameters  : 
 *   id - Unique identifier to check.
 * 
 * Returns     : bool - True if ID exists, false otherwise.
 *******************************************************************************/
bool Bank::idExists(int id) {
    for (auto acc : accounts) {
        if (acc->getId() == id)
            return true;
    }
    return false;
}

/*******************************************************************************
 * Function    : loadFromFile
 * Description : Reads comma-separated records from "data.txt" and populates 
 *               the bank with SavingsAccount and CheckingAccount objects.
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
