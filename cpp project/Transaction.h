/*******************************************************************************
 * File        : Transaction.h
 * Author      : samar salah 
 * Date        : 29/07/2026
 * Description : Header file for the Transaction class, representing a record 
 *               of an account transaction.
 *******************************************************************************/

#pragma once

#include <string>

using namespace std;

/*******************************************************************************
 * Class       : Transaction
 * Description : Stores details about individual financial transactions such as 
 *               operation type, participating accounts, amount, and timestamp.
 *******************************************************************************/
class Transaction
{
private:
    string timestamp;
    string operation;
    string sourceAccount;
    string destinationAccount;
    double amount;
    string description;

public:
    /*******************************************************************************
     * Function    : Transaction
     * Description : Constructor to initialize a transaction with specified details 
     *               and record the current timestamp.
     * 
     * Parameters  : 
     *   operation          - Type of operation (e.g., Deposit, Withdraw, Transfer).
     *   sourceAccount      - ID of the initiating/source account.
     *   destinationAccount - ID of the destination account (if applicable).
     *   amount             - Monetary amount involved in the transaction.
     *   description        - Additional notes or description of the transaction.
     * 
     * Returns     : None.
     *******************************************************************************/
    Transaction(
        string operation,
        string sourceAccount,
        string destinationAccount,
        double amount,
        string description
    );

    /*******************************************************************************
     * Function    : getTimestamp
     * Description : Returns the creation timestamp of the transaction.
     * 
     * Parameters  : None.
     * 
     * Returns     : string - The timestamp string.
     *******************************************************************************/
    string getTimestamp() const;

    /*******************************************************************************
     * Function    : toString
     * Description : Formats and returns a human-readable string representation of 
     *               the transaction record.
     * 
     * Parameters  : None.
     * 
     * Returns     : string - Formatted transaction details.
     *******************************************************************************/
    string toString() const;
};
