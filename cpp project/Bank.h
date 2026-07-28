/*******************************************************************************
 * File        : Bank.h
 * Author      : Your Name
 * Date        : 28/07/2026
 * Description : Header file for the Bank class, which manages multiple bank accounts.
 *******************************************************************************/
#pragma once

#include <vector>
#include <memory>
#include <string>
#include "Account.h"

using namespace std;

/*******************************************************************************
 * Class       : Bank
 * Description : Manages a collection of accounts, supporting operations like
 *               creation, deposits, withdrawals, transfers, and file persistence.
 *******************************************************************************/
class Bank
{
private:
    vector<shared_ptr<Account>> accounts;

    /*******************************************************************************
     * Function    : findAccount
     * Description : Helper function to search for an account by its unique ID.
     *
     * Parameters  :
     *   id - The unique account ID to search for.
     *
     * Returns     : shared_ptr<Account> - Pointer to the account if found, or nullptr.
     *******************************************************************************/
    shared_ptr<Account> findAccount(const string& id);

public:
    /*******************************************************************************
     * Function    : Bank
     * Description : Default constructor for initializing a Bank object.
     *
     * Parameters  : None.
     *
     * Returns     : None.
     *******************************************************************************/
    Bank();

    /*******************************************************************************
     * Function    : createSavingsAccount
     * Description : Creates a new SavingsAccount and adds it to the system.
     *
     * Parameters  :
     *   id      - Unique identifier for the new savings account.
     *   owner   - Name of the account holder.
     *   balance - Initial balance.
     *
     * Returns     : void
     *******************************************************************************/
    void createSavingsAccount(string id, string owner, double balance);

    /*******************************************************************************
     * Function    : createCheckingAccount
     * Description : Creates a new CheckingAccount and adds it to the system.
     *
     * Parameters  :
     *   id      - Unique identifier for the new checking account.
     *   owner   - Name of the account holder.
     *   balance - Initial balance.
     *
     * Returns     : void
     *******************************************************************************/
    void createCheckingAccount(string id, string owner, double balance);

    /*******************************************************************************
     * Function    : deposit
     * Description : Deposits money into a specified account.
     *
     * Parameters  :
     *   id     - Unique identifier of the target account.
     *   amount - The amount of money to deposit.
     *
     * Returns     : void
     *******************************************************************************/
    void deposit(string id, double amount);

    /*******************************************************************************
     * Function    : withdraw
     * Description : Withdraws money from a specified account.
     *
     * Parameters  :
     *   id     - Unique identifier of the target account.
     *   amount - The amount of money to withdraw.
     *
     * Returns     : void
     *******************************************************************************/
    void withdraw(string id, double amount);

    /*******************************************************************************
     * Function    : transfer
     * Description : Transfers funds from one account to another.
     *
     * Parameters  :
     *   fromId - ID of the account money is withdrawn from.
     *   toId   - ID of the account money is deposited to.
     *   amount - The amount of money to transfer.
     *
     * Returns     : void
     *******************************************************************************/
    void transfer(string fromId, string toId, double amount);

    /*******************************************************************************
     * Function    : displayAccounts
     * Description : Prints the details of all accounts currently managed by the bank.
     *
     * Parameters  : None.
     *
     * Returns     : void
     *******************************************************************************/
    void displayAccounts() const;

    /*******************************************************************************
     * Function    : loadAccounts
     * Description : Loads account data from a file into memory.
     *
     * Parameters  :
     *   filename - Name or path of the file to load data from.
     *
     * Returns     : void
     *******************************************************************************/
    void loadAccounts(const string& filename);

    /*******************************************************************************
     * Function    : saveAccounts
     * Description : Saves all managed account data to a file for persistence.
     *
     * Parameters  :
     *   filename - Name or path of the destination file.
     *
     * Returns     : void
     *******************************************************************************/
    void saveAccounts(const string& filename) const;

    /*******************************************************************************
     * Function    : logTransaction
     * Description : Logs a transaction or activity message to a file or log target.
     *
     * Parameters  :
     *   message - Description of the transaction to record.
     *
     * Returns     : void
     *******************************************************************************/
    void logTransaction(const string& message);
};

