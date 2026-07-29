/*******************************************************************************
 * File        : Account.cpp
 * Author      : samar salah 
 * Date        : 29/07/2026
 * Description : Implementation of the Account class member functions.
 *******************************************************************************/

#include "Account.h"
#include <stdexcept>
#include<string>

 /*******************************************************************************
  * Function    : Account
  * Description : Parameterized constructor for initializing account properties.
  *
  * Parameters  :
  *   i - Unique identifier for the account.
  *   n - Account holder's name.
  *   b - Initial balance for the account.
  *
  * Returns     : None.
  *******************************************************************************/
Account::Account(int i, string n, double b) {
    id = i;
    name = n;
    balance = b;
}

/*******************************************************************************
 * Function    : getId
 * Description : Retrieves the account ID.
 *
 * Parameters  : None.
 *
 * Returns     : int - The account ID.
 *******************************************************************************/
int Account::getId()const {
    return id;
}

/*******************************************************************************
 * Function    : getName
 * Description : Retrieves the account holder's name.
 *
 * Parameters  : None.
 *
 * Returns     : string - The account holder's name.
 *******************************************************************************/
string Account::getName()const {
    return name;
}

/*******************************************************************************
 * Function    : getBalance
 * Description : Retrieves the current account balance.
 *
 * Parameters  : None.
 *
 * Returns     : double - The current balance.
 *******************************************************************************/
double Account::getBalance()const {
    return balance;
}

/*******************************************************************************
 * Function    : deposit
 * Description : Deposits a specified amount into the account. Throws an
 *               invalid_argument exception if the deposit amount is zero or negative.
 *
 * Parameters  :
 *   amount - The amount to be deposited.
 *
 * Returns     : void
 *******************************************************************************/
void Account::deposit(double amount) {
    if (amount <= 0)
        throw invalid_argument("Invalid deposit");

    balance += amount;
}

/*******************************************************************************
 * Function    : save
 * Description : Serializes account data (ID, name, balance) into a
 *               comma-separated string format.
 *
 * Parameters  : None.
 *
 * Returns     : string - Formatted account details.
 *******************************************************************************/
string Account::save() {
    return to_string(id) + "," + name + "," + to_string(balance);
}
