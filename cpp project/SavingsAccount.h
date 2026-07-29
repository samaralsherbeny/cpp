/*******************************************************************************
 * File        : SavingsAccount.h
 * Author      : samar salah 
 * Date        : 29/07/2026
 * Description : Header file for the SavingsAccount class, derived from Account.
 *******************************************************************************/

#pragma once
#include "Account.h"

 /*******************************************************************************
  * Class       : SavingsAccount
  * Description : Represents a savings account object derived from the Account base class.
  *******************************************************************************/
class SavingsAccount : public Account {
public:
    /*******************************************************************************
     * Function    : SavingsAccount
     * Description : Constructor to initialize a SavingsAccount instance.
     *
     * Parameters  :
     *   i - Unique identifier for the account.
     *   n - Account holder's name.
     *   b - Initial balance amount.
     *
     * Returns     : None.
     *******************************************************************************/
    SavingsAccount(int i, string n, double b);

    /*******************************************************************************
     * Function    : withdraw
     * Description : Withdraws a specified amount from the savings account.
     *
     * Parameters  :
     *   amount - The monetary amount to withdraw.
     *
     * Returns     : void
     *******************************************************************************/
    void withdraw(double amount);

    /*******************************************************************************
     * Function    : getType
     * Description : Returns the type of the account ("Savings").
     *
     * Parameters  : None.
     *
     * Returns     : string - The string representing the account type.
     *******************************************************************************/
    string getType();
};

