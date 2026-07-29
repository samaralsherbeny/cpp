/*******************************************************************************
 * File        : SavingsAccount.h
 * Author      : samar salah 
 * Date        : 28/07/2026
 * Description : Header file for the SavingsAccount class, derived from Account.
 *******************************************************************************/

#pragma once

#include "Account.h"
#include <string>
using namespace std;

/*******************************************************************************
 * Class       : SavingsAccount
 * Description : Represents a savings account object derived from the Account base class.
 *******************************************************************************/
class SavingsAccount : public Account
{
public:
    /*******************************************************************************
     * Function    : SavingsAccount
     * Description : Constructor to initialize a SavingsAccount instance.
     * 
     * Parameters  : 
     *   id      - Unique identifier for the account.
     *   owner   - Name of the account holder.
     *   balance - Initial balance amount.
     * 
     * Returns     : None.
     *******************************************************************************/
    SavingsAccount(string id, string owner, double balance);

    /*******************************************************************************
     * Function    : getType
     * Description : Returns the type of the account ("Savings Account").
     * 
     * Parameters  : None.
     * 
     * Returns     : string - The string representing the account type.
     *******************************************************************************/
    string getType() const override;

    /*******************************************************************************
     * Function    : saveData
     * Description : Formats and returns the savings account data for saving/storage.
     * 
     * Parameters  : None.
     * 
     * Returns     : string - Formatted string containing account details.
     *******************************************************************************/
    string saveData() const override;
};
