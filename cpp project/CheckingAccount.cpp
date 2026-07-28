/*******************************************************************************
 * File        : CheckingAccount.cpp
 * Author      : Your Name
 * Date        : 28/07/2026
 * Description : Implementation of the CheckingAccount class member functions.
 *******************************************************************************/

#include "CheckingAccount.h"
#include <sstream>

 /*******************************************************************************
  * Function    : CheckingAccount
  * Description : Constructor for CheckingAccount that passes parameters to the
  *               Account base class constructor.
  *
  * Parameters  :
  *   id      - Unique identifier for the account.
  *   owner   - Name of the account holder.
  *   balance - Initial balance amount.
  *
  * Returns     : None.
  *******************************************************************************/
CheckingAccount::CheckingAccount(string id, string owner, double balance)
    : Account(id, owner, balance)
{
}

/*******************************************************************************
 * Function    : getType
 * Description : Returns the specific type name of this account.
 *
 * Parameters  : None.
 *
 * Returns     : string - "Checking"
 *******************************************************************************/
string CheckingAccount::getType() const
{
    return "Checking";
}

/*******************************************************************************
 * Function    : saveData
 * Description : Serializes checking account data into a comma-separated string format.
 *
 * Parameters  : None.
 *
 * Returns     : string - Formatted account details (Type, ID, Owner, Balance).
 *******************************************************************************/
string CheckingAccount::saveData() const
{
    stringstream ss;

    ss << "Checking,"
        << id << ","
        << owner << ","
        << balance;

    return ss.str();
}
