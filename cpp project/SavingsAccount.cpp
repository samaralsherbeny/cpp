/*******************************************************************************
 * File        : SavingsAccount.cpp
 * Author      : samar salah 
 * Date        : 29/07/2026
 * Description : Implementation of the SavingsAccount class member functions.
 *******************************************************************************/

#include "SavingsAccount.h"
#include <stdexcept>

 /*******************************************************************************
  * Function    : SavingsAccount
  * Description : Constructor for SavingsAccount that passes parameters to the
  *               Account base class constructor.
  *
  * Parameters  :
  *   i - Unique identifier for the account.
  *   n - Account holder's name.
  *   b - Initial balance amount.
  *
  * Returns     : None.
  *******************************************************************************/
SavingsAccount::SavingsAccount(int i, string n, double b)
    : Account(i, n, b) {
}

/*******************************************************************************
 * Function    : withdraw
 * Description : Withdraws a specified amount from the savings account. Throws
 *               an invalid_argument exception if the amount is less than or
 *               equal to zero, or exceeds the current balance.
 *
 * Parameters  :
 *   amount - The monetary amount to withdraw.
 *
 * Returns     : void
 *******************************************************************************/
void SavingsAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance)
        throw invalid_argument("Invalid withdraw");

    balance -= amount;
}

/*******************************************************************************
 * Function    : getType
 * Description : Returns the specific type name of this account.
 *
 * Parameters  : None.
 *
 * Returns     : string - "Savings"
 *******************************************************************************/
string SavingsAccount::getType() {
    return "Savings";
}
