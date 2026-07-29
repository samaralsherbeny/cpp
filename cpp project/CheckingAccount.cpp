/*******************************************************************************
 * File        : CheckingAccount.cpp
 * Author      : samar salah 
 * Date        : 29/07/2026
 * Description : Implementation of the CheckingAccount class member functions.
 *******************************************************************************/

#include "CheckingAccount.h"
#include <stdexcept>

 /*******************************************************************************
  * Function    : CheckingAccount
  * Description : Constructor for CheckingAccount that passes parameters to the
  *               Account base class constructor.
  *
  * Parameters  :
  *   i - Unique identifier for the account.
  *   n - Account holder's name.
  *   b - Initial balance amount.
  *
  * Returns     : None.
  *******************************************************************************/
CheckingAccount::CheckingAccount(int i, string n, double b)
    : Account(i, n, b) {
}

/*******************************************************************************
 * Function    : withdraw
 * Description : Withdraws a specified amount from the checking account. Throws
 *               an invalid_argument exception if the amount is less than or
 *               equal to zero, or if funds are insufficient.
 *
 * Parameters  :
 *   amount - The monetary amount to withdraw.
 *
 * Returns     : void
 *******************************************************************************/
void CheckingAccount::withdraw(double amount) {
    if (amount <= 0)
        throw invalid_argument("Invalid amount");

    if (balance - amount < 0)
        throw invalid_argument("Not enough money");

    balance -= amount;
}

/*******************************************************************************
 * Function    : getType
 * Description : Returns the specific type name of this account.
 *
 * Parameters  : None.
 *
 * Returns     : string - "Checking"
 *******************************************************************************/
string CheckingAccount::getType() {
    return "Checking";
}
