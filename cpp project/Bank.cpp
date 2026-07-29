/*******************************************************************************
 * File        : Bank.cpp
 * Author      : samar salah 
 * Date        : 28/07/2026
 * Description : Implementation of the Bank class member functions.
 *******************************************************************************/

#include "Bank.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>

using namespace std;

/*******************************************************************************
 * Function    : Bank
 * Description : Default constructor for the Bank class.
 * 
 * Parameters  : None.
 * 
 * Returns     : None.
 *******************************************************************************/
Bank::Bank()
{
}

/*******************************************************************************
 * Function    : findAccount
 * Description : Helper method that searches for an account in the accounts vector
 *               matching the specified unique ID using std::find_if.
 * 
 * Parameters  : 
 *   id - Unique identifier of the account to search for.
 * 
 * Returns     : shared_ptr<Account> - Pointer to account if found, otherwise nullptr.
 *******************************************************************************/
shared_ptr<Account> Bank::findAccount(const string& id)
{
    auto it = find_if(accounts.begin(), accounts.end(),
        [&](shared_ptr<Account> account)
        {
            return account->getId() == id;
        });

    if(it != accounts.end())
        return *it;

    return nullptr;
}

/*******************************************************************************
 * Function    : createSavingsAccount
 * Description : Instantiates and registers a new SavingsAccount. Throws an
 *               exception if an account with the given ID already exists.
 * 
 * Parameters  : 
 *   id      - Unique identifier for the account.
 *   owner   - Account owner's name.
 *   balance - Starting account balance.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::createSavingsAccount(string id, string owner, double balance)
{
    if(findAccount(id))
        throw runtime_error("Account already exists.");

    accounts.push_back(make_shared<SavingsAccount>(id, owner, balance));
}

/*******************************************************************************
 * Function    : createCheckingAccount
 * Description : Instantiates and registers a new CheckingAccount. Throws an
 *               exception if an account with the given ID already exists.
 * 
 * Parameters  : 
 *   id      - Unique identifier for the account.
 *   owner   - Account owner's name.
 *   balance - Starting account balance.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::createCheckingAccount(string id, string owner, double balance)
{
    if(findAccount(id))
        throw runtime_error("Account already exists.");

    accounts.push_back(make_shared<CheckingAccount>(id, owner, balance));
}

/*******************************************************************************
 * Function    : deposit
 * Description : Deposits funds into a target account identified by ID and logs
 *               the transaction. Throws runtime_error if account is not found.
 * 
 * Parameters  : 
 *   id     - Target account identifier.
 *   amount - Deposit amount.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::deposit(string id, double amount)
{
    auto account = findAccount(id);

    if(!account)
        throw runtime_error("Account not found.");

    account->deposit(amount);

    logTransaction("Deposit into account " + id);
}

/*******************************************************************************
 * Function    : withdraw
 * Description : Withdraws funds from a target account identified by ID and logs
 *               the transaction. Throws runtime_error if missing or insufficient funds.
 * 
 * Parameters  : 
 *   id     - Target account identifier.
 *   amount - Withdrawal amount.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::withdraw(string id, double amount)
{
    auto account = findAccount(id);

    if(!account)
        throw runtime_error("Account not found.");

    if(!account->withdraw(amount))
        throw runtime_error("Insufficient balance.");

    logTransaction("Withdraw from account " + id);
}

/*******************************************************************************
 * Function    : transfer
 * Description : Transfers funds between two accounts and logs the transaction. 
 *               Validates target accounts and balance sufficiency.
 * 
 * Parameters  : 
 *   fromId - ID of the source account.
 *   toId   - ID of the destination account.
 *   amount - Transfer amount.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::transfer(string fromId, string toId, double amount)
{
    if(fromId == toId)
        throw runtime_error("Cannot transfer to the same account.");

    auto from = findAccount(fromId);
    auto to = findAccount(toId);

    if(!from || !to)
        throw runtime_error("Account not found.");

    if(!from->withdraw(amount))
        throw runtime_error("Insufficient balance.");

    to->deposit(amount);

    logTransaction("Transfer from " + fromId + " to " + toId);
}

/*******************************************************************************
 * Function    : displayAccounts
 * Description : Iterates through all registered accounts and prints their details.
 * 
 * Parameters  : None.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::displayAccounts() const
{
    for(const auto& account : accounts)
    {
        account->display();
        cout << "---------------------\n";
    }
}

/*******************************************************************************
 * Function    : saveAccounts
 * Description : Writes serialized string data for each account to a target file.
 * 
 * Parameters  : 
 *   filename - Name or path of the output file.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::saveAccounts(const string& filename) const
{
    ofstream file(filename);

    for(const auto& account : accounts)
    {
        file << account->saveData() << endl;
    }
}

/*******************************************************************************
 * Function    : loadAccounts
 * Description : Reads comma-separated account records from a file and reconstitutes 
 *               the corresponding SavingsAccount or CheckingAccount objects.
 * 
 * Parameters  : 
 *   filename - Name or path of the input file.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::loadAccounts(const string& filename)
{
    ifstream file(filename);

    if(!file)
        return;

    string line;

    while(getline(file, line))
    {
        stringstream ss(line);

        string type, id, owner, balanceStr;

        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, owner, ',');
        getline(ss, balanceStr, ',');

        double balance = stod(balanceStr);

        if(type == "Savings")
            accounts.push_back(make_shared<SavingsAccount>(id, owner, balance));
        else if(type == "Checking")
            accounts.push_back(make_shared<CheckingAccount>(id, owner, balance));
    }
}

/*******************************************************************************
 * Function    : logTransaction
 * Description : Appends a timestamped transaction log message to "transactions.txt".
 * 
 * Parameters  : 
 *   message - Description of the completed transaction.
 * 
 * Returns     : void
 *******************************************************************************/
void Bank::logTransaction(const string& message)
{
    ofstream file("transactions.txt", ios::app);

    time_t now = time(nullptr);

    file << ctime(&now)
         << message
         << "\n------------------\n";
}
