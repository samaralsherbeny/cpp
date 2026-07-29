/*******************************************************************************
 * File        : Bank.h
 * Author      : samar salah
 * Date        : 29/07/2026
 * Description : Header file for the Bank class, managing a collection of bank
 *               accounts and their operations.
 *******************************************************************************/

#pragma once

#include <vector>
#include <memory>
#include "Account.h"

 /*******************************************************************************
  * Class       : Bank
  * Description : Manages multiple accounts, allowing creation, retrieval,
  *               financial transactions, display, and file storage/retrieval.
  *******************************************************************************/
class Bank {
private:
    vector<shared_ptr<Account>> accounts;

public:
    /*******************************************************************************
     * Function    : addAccount
     * Description : Adds a new account pointer to the bank's account repository.
     *
     * Parameters  :
     *   acc - Shared pointer to the account object being added.
     *
     * Returns     : void
     *******************************************************************************/
    void addAccount(shared_ptr<Account> acc);

    /*******************************************************************************
     * Function    : findAccount
     * Description : Searches for an account by its unique integer ID.
     *
     * Parameters  :
     *   id - Unique identifier of the target account.
     *
     * Returns     : shared_ptr<Account> - Pointer to the account if found, or nullptr.
     *******************************************************************************/
    shared_ptr<Account> findAccount(int id);

    /*******************************************************************************
     * Function    : deposit
     * Description : Deposits a specified amount into the account with the given ID.
     *
     * Parameters  :
     *   id     - Unique identifier of the target account.
     *   amount - Monetary amount to deposit.
     *
     * Returns     : void
     *******************************************************************************/
    void deposit(int id, double amount);

    /*******************************************************************************
     * Function    : withdraw
     * Description : Withdraws a specified amount from the account with the given ID.
     *
     * Parameters  :
     *   id     - Unique identifier of the target account.
     *   amount - Monetary amount to withdraw.
     *
     * Returns     : void
     *******************************************************************************/
    void withdraw(int id, double amount);

    /*******************************************************************************
     * Function    : transfer
     * Description : Transfers funds from a source account to a destination account.
     *
     * Parameters  :
     *   from   - ID of the account being debited.
     *   to     - ID of the account receiving the funds.
     *   amount - Monetary amount to transfer.
     *
     * Returns     : void
     *******************************************************************************/
    void transfer(int from, int to, double amount);

    /*******************************************************************************
     * Function    : showAccounts
     * Description : Displays information for all accounts managed by the bank.
     *
     * Parameters  : None.
     *
     * Returns     : void
     *******************************************************************************/
    void showAccounts();

    /*******************************************************************************
     * Function    : saveToFile
     * Description : Saves all managed account data to a file for persistent storage.
     *
     * Parameters  : None.
     *
     * Returns     : void
     *******************************************************************************/
    void saveToFile();

    /*******************************************************************************
     * Function    : loadFromFile
     * Description : Loads stored account records from a file into memory.
     *
     * Parameters  : None.
     *
     * Returns     : void
     *******************************************************************************/
    void loadFromFile();
};

