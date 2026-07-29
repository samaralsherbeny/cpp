/*******************************************************************************
 * File        : SavingsAccount.cpp
 * Author      : samar salah 
 * Date        : 28/07/2026
 * Description : Implementation of the SavingsAccount class member functions.
 *******************************************************************************/

#include "SavingsAccount.h"
#include <sstream>

 /*******************************************************************************
  * Function    : SavingsAccount
  * Description : Constructor for SavingsAccount that passes parameters to the
  *               Account base class constructor.
  *
  * Parameters  :
  *   id      - Unique identifier for the account.
  *   owner   - Name of the account holder.
  *   balance - Initial balance amount.
  *
  * Returns     : None.
  *******************************************************************************/
SavingsAccount::SavingsAccount(string id, string owner, double balance)
    : Account(id, owner, balance)
{

}

/*******************************************************************************
 * Function    : getType
 * Description : Returns the specific type name of this account.
 *
 * Parameters  : None.
 *
 * Returns     : string - "Savings"
 *******************************************************************************/
string SavingsAccount::getType() const
{
    return "Savings";
}

/*******************************************************************************
 * Function    : saveData
 * Description : Serializes savings account data into a comma-separated string format.
 *
 * Parameters  : None.
 *
 * Returns     : string - Formatted account details (Type, ID, Owner, Balance).
 *******************************************************************************/
string SavingsAccount::saveData() const
{
    stringstream ss;

    ss << "Savings,"
        << id << ","
        << owner << ","
        << balance;

    return ss.str();
}
