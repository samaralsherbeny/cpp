/*******************************************************************************
 * File        : Account.cpp
 * Author      : samar salah 
 * Date        : 27/07/2026
 * Description : Implementation of the Account class member functions.
 *******************************************************************************/

#include "Account.h"

 /*******************************************************************************
  * Function    : Account
  * Description : Parameterized constructor for initializing account properties.
  *
  * Parameters  :
  *   id      - Unique identifier for the account.
  *   owner   - Name of the account owner.
  *   balance - Initial balance for the account.
  *
  * Returns     : None.
  *******************************************************************************/

Account::Account(string id, string owner, double balance)
{
    this->id = id;
    this->owner = owner;
    this->balance = balance;
}
/*******************************************************************************
 * Function    : getId
 * Description : Retrieves the account ID.
 *
 * Parameters  : None.
 *
 * Returns     : string - The account ID.
 *******************************************************************************/

string Account::getId() const
{
    return id;
}
/*******************************************************************************
 * Function    : getOwner
 * Description : Retrieves the owner's name.
 *
 * Parameters  : None.
 *
 * Returns     : string - The account owner's name.
 *******************************************************************************/

string Account::getOwner() const
{
    return owner;
}
/*******************************************************************************
 * Function    : getBalance
 * Description : Retrieves the current account balance.
 *
 * Parameters  : None.
 *
 * Returns     : double - The current balance.
 *******************************************************************************/

double Account::getBalance() const
{
    return balance;
}
/*******************************************************************************
 * Function    : deposit
 * Description : Deposits a specified amount into the account. Throws an
 *               exception if the deposit amount is zero or negative.
 *
 * Parameters  :
 *   amount - The amount to be deposited.
 *
 * Returns     : void
 *******************************************************************************/

void Account::deposit(double amount)
{
    if (amount <= 0)
        throw invalid_argument("Invalid deposit amount.");

    balance += amount;
}
/*******************************************************************************
 * Function    : withdraw
 * Description : Withdraws a specified amount from the account if valid and
 *               sufficient funds exist. Throws an exception for invalid amounts.
 *
 * Parameters  :
 *   amount - The amount to withdraw.
 *
 * Returns     : bool - True if withdrawal was successful, false if insufficient balance.
 *******************************************************************************/

bool Account::withdraw(double amount)
{
    if (amount <= 0)
        throw invalid_argument("Invalid withdrawal amount.");

    if (amount > balance)
        return false;

    balance -= amount;
    return true;
}
/*******************************************************************************
 * Function    : display
 * Description : Prints account details (ID, Owner, Type, Balance) to standard output.
 *
 * Parameters  : None.
 *
 * Returns     : void
 *******************************************************************************/

void Account::display() const
{
    cout << "ID: " << id << endl;
    cout << "Owner: " << owner << endl;
    cout << "Type: " << getType() << endl;
    cout << "Balance: $" << balance << endl;
}
