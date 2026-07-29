/*******************************************************************************
 * File        : Account.h
 * Author      : samar salah 
 * Date        : 27/07/2026
 * Description : Abstract base class representing a generic bank account.
 *******************************************************************************/

#pragma once 
#define ACCOUNT_H 
#include <iostream>
#include <string>
using namespace std;
/*******************************************************************************
 * Class       : Account
 * Description : Abstract class (cannot be instantiated directly).
 *               Serves as a blueprint for creating specific account objects.
 *******************************************************************************/

class Account
{
protected:// accesseble to derived classes to access the members of the base class
    string id;
    string owner;
    double balance;

public:// accessible to all classes

    /*******************************************************************************
     * Function    : Account
     * Description : Constructor to initialize the values of the account object.
     *
     * Parameters  :
     *   id      - Unique identifier for the account.
     *   owner   - Name of the account holder.
     *   balance - Initial balance amount.
     *
     * Returns     : None.
     *******************************************************************************/

    Account(string id, string owner, double balance);

    /*******************************************************************************
     * Function    : ~Account
     * Description : Virtual destructor to avoid resource leaks when deleting derived objects.
     *
     * Parameters  : None.
     *
     * Returns     : None.
     *******************************************************************************/

    virtual ~Account() {}

    /*******************************************************************************
     * Function    : getId
     * Description : Getter function to return the account ID.
     *
     * Parameters  : None.
     *
     * Returns     : string - The account ID.
     *******************************************************************************/

    string getId() const;

    /*******************************************************************************
     * Function    : getOwner
     * Description : Getter function to return the owner's name.
     *
     * Parameters  : None.
     *
     * Returns     : string - The owner's name.
     *******************************************************************************/

    string getOwner() const;

    /*******************************************************************************
     * Function    : getBalance
     * Description : Getter function to return the current balance.
     *
     * Parameters  : None.
     *
     * Returns     : double - The account balance.
     *******************************************************************************/

    double getBalance() const;

    /*******************************************************************************
     * Function    : deposit
     * Description : Virtual function that adds money to the account balance.
     *               Can be overridden by derived classes.
     *
     * Parameters  :
     *   amount - The amount of money to deposit.
     *
     * Returns     : void
     *******************************************************************************/

    virtual void deposit(double amount);

    /*******************************************************************************
     * Function    : withdraw
     * Description : Virtual function that subtracts money from the account balance.
     *               Can be overridden by derived classes.
     *
     * Parameters  :
     *   amount - The amount of money to withdraw.
     *
     * Returns     : bool - True if withdrawal was successful, false otherwise.
	 *******************************************************************************/

    virtual bool withdraw(double amount);

    /*******************************************************************************
     * Function    : getType
     * Description : Pure virtual function to get the account type name.
     *
     * Parameters  : None.
     *
     * Returns     : string - Name/type of the derived account.
     *******************************************************************************/

	virtual string getType() const = 0;

    /*******************************************************************************
     * Function    : display
     * Description : Virtual function to print account details.
     *               Can be overridden by derived classes for custom display.
     *
     * Parameters  : None.
     *
     * Returns     : void
	 *******************************************************************************/

	virtual void display() const;

    /*******************************************************************************
     * Function    : saveData
     * Description : Pure virtual function to save account data to a string.
     *               Must be implemented by derived classes.
     *
     * Parameters  : None.
     *
     * Returns     : string - Formatted account data for saving.
	 *******************************************************************************/

	virtual string saveData() const = 0;
};
