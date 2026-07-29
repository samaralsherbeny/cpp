/*******************************************************************************
 * File        : CheckingAccount.h
 * Author      : samar salah
 * Date        : 29/07/2026
 * Description : Header file for the CheckingAccount class, derived from Account.
 *******************************************************************************/

#pragma once

#include "Account.h"

 /*******************************************************************************
  * Class       : CheckingAccount
  * Description : Represents a checking account object derived from the Account base class.
  *******************************************************************************/
class CheckingAccount : public Account {
public:
    /*******************************************************************************
     * Function    : CheckingAccount
     * Description : Constructor to initialize a CheckingAccount instance.
     *
     * Parameters  :
     *   i - Unique identifier for the account.
     *   n - Account holder's name.
     *   b - Initial balance amount.
     *
     * Returns     : None.
     *******************************************************************************/
    CheckingAccount(int i, string n, double b);

    /*******************************************************************************
     * Function    : withdraw
     * Description : Withdraws a specified amount from the checking account.
     *
     * Parameters  :
     *   amount - The monetary amount to withdraw.
     *
     * Returns     : void
     *******************************************************************************/
    void withdraw(double amount);

    /*******************************************************************************
     * Function    : getType
     * Description : Returns the type of the account ("Checking").
     *
     * Parameters  : None.
     *
     * Returns     : string - The string representing the account type.
     *******************************************************************************/
    string getType();
};


