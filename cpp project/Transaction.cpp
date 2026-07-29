/*******************************************************************************
 * File        : Transaction.cpp
 * Author      : samar salah 
 * Date        : 29/07/2026
 * Description : Implementation of the Transaction class member functions.
 *******************************************************************************/

#include "Transaction.h"

#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

/*******************************************************************************
 * Function    : Transaction
 * Description : Constructor for Transaction that initializes the transaction 
 *               fields and generates a formatted timestamp for the current time.
 * 
 * Parameters  : 
 *   operation          - Type of financial operation.
 *   sourceAccount      - ID of the source account.
 *   destinationAccount - ID of the destination account.
 *   amount             - Monetary amount transferred or processed.
 *   description        - Brief summary or details of the transaction.
 * 
 * Returns     : None.
 *******************************************************************************/
Transaction::Transaction(
    string operation,
    string sourceAccount,
    string destinationAccount,
    double amount,
    string description)
{
    this->operation = operation;
    this->sourceAccount = sourceAccount;
    this->destinationAccount = destinationAccount;
    this->amount = amount;
    this->description = description;

    time_t now = time(nullptr);

    tm* localTime = localtime(&now);

    stringstream ss;

    ss << put_time(localTime, "%Y-%m-%d %H:%M:%S");

    timestamp = ss.str();
}

/*******************************************************************************
 * Function    : getTimestamp
 * Description : Getter function to retrieve the transaction timestamp string.
 * 
 * Parameters  : None.
 * 
 * Returns     : string - The recorded timestamp (%Y-%m-%d %H:%M:%S format).
 *******************************************************************************/
string Transaction::getTimestamp() const
{
    return timestamp;
}

/*******************************************************************************
 * Function    : toString
 * Description : Formats the transaction attributes into a multi-line output string.
 * 
 * Parameters  : None.
 * 
 * Returns     : string - Multi-line string containing transaction information.
 *******************************************************************************/
string Transaction::toString() const
{
    stringstream ss;

    ss << "Timestamp: " << timestamp << endl;
    ss << "Operation: " << operation << endl;
    ss << "Source: " << sourceAccount << endl;
    ss << "Destination: " << destinationAccount << endl;
    ss << "Amount: " << amount << endl;
    ss << "Description: " << description << endl;
    ss << "----------------------------------------" << endl;

    return ss.str();
}
