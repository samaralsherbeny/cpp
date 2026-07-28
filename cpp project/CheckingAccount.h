/*******************************************************************************
 * File        : CheckingAccount.h
 * Author      : Your Name
 * Date        : 28/07/2026
 * Description : Header file for the CheckingAccount class, derived from Account.
 *******************************************************************************/

#pragma once

#include "Account.h"

 /*******************************************************************************
  * Class       : CheckingAccount
  * Description : Represents a checking account object derived from the Account base class.
  *******************************************************************************/
class CheckingAccount : public Account
{
public:
    /*******************************************************************************
     * Function    : CheckingAccount
     * Description : Constructor to initialize a CheckingAccount instance.
     *
     * Parameters  :
     *   id      - Unique identifier for the account.
     *   owner   - Name of the account holder.
     *   balance - Initial balance amount.
     *
     * Returns     : None.
     *******************************************************************************/
    CheckingAccount(string id, string owner, double balance);

    /*******************************************************************************
     * Function    : getType
     * Description : Returns the type of the account ("Checking").
     *
     * Parameters  : None.
     *
     * Returns     : string - The string representing the account type.
     *******************************************************************************/
    string getType() const override;

    /*******************************************************************************
     * Function    : saveData
     * Description : Formats and returns the checking account data for saving/storage.
     *
     * Parameters  : None.
     *
     * Returns     : string - Formatted string containing account details.
     *******************************************************************************/
    string saveData() const override;
};
