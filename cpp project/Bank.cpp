/*******************************************************************************
 * File        : Bank.cpp
 * Author      : samar salah 
 * Date        : 30/07/2026
 * Description : Implementation of the Bank class member functions, including
 *               account management, persistence, and custom exception handling.
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
 * Description : Adds a new account to the bank's storage. Throws a 
 *               DuplicateIDException if an account with the same ID already exists.
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
 * Returns     : shared_ptr<Account> - Shared pointer to the matching account.
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
 * Description : Deposits a specified monetary amount into the account matching 
 *               the given ID.
 *
 * Parameters  :
 *   id     - Unique identifier of the target account.
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
 * Description : Withdraws a specified monetary amount from the account matching 
 *               the given ID.
 *
 * Parameters  :
 *   id     - Unique identifier of the target account.
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
 * Description : Transfers money from a source account to a destination account. 
 *               Ensures the source and destination account IDs are distinct.
 *
 * Parameters  :
 *   from   - Unique identifier of the source account.
 *   to     - Unique identifier of the destination account.
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
 * Description : Displays the details (ID, Owner Name, Type, and Balance) for 
 *               all registered accounts to standard output.
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
 * Description : Writes all active account records in comma-separated format 
 *               to "data.txt" for persistent storage.
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
 * Description : Helper function to determine whether an account with the 
 *               specified ID is already registered in the bank repository.
 *
 * Parameters  :
 *   id - Unique identifier to search for.
 *
 * Returns     : bool - True if the ID exists, false otherwise.
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
 * Description : Reads stored account data line-by-line from "data.txt" and 
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
