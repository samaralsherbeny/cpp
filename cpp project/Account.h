/*******************************************************************************
 * File        : Account.h
 * Author      : samar salah 
 * Date        : 29/07/2026
 * Description : Abstract base class header for bank accounts.
 *******************************************************************************/
#pragma once

#include <iostream>
using namespace std;

/*******************************************************************************
 * Class       : Account
 * Description : Abstract base class representing a generic bank account.
 *******************************************************************************/
class Account {
protected:
    int id;
    string name;
    double balance;

public:
    /*******************************************************************************
     * Function    : Account
     * Description : Parameterized constructor to initialize account attributes.
     *
     * Parameters  :
     *   i - Unique identifier for the account.
     *   n - Account holder's name.
     *   b - Initial balance.
     *
     * Returns     : None.
     *******************************************************************************/
    Account(int i, string n, double b);

    /*******************************************************************************
     * Function    : getId
     * Description : Getter function to retrieve the account ID.
     *
     * Parameters  : None.
     *
     * Returns     : int - Account ID.
     *******************************************************************************/
    int getId() const;

    /*******************************************************************************
     * Function    : getName
     * Description : Getter function to retrieve the account holder's name.
     *
     * Parameters  : None.
     *
     * Returns     : string - Account holder's name.
     *******************************************************************************/
    string getName()const;

    /*******************************************************************************
     * Function    : getBalance
     * Description : Getter function to retrieve the current account balance.
     *
     * Parameters  : None.
     *
     * Returns     : double - Current balance.
     *******************************************************************************/
    double getBalance()const;

    /*******************************************************************************
     * Function    : deposit
     * Description : Deposits a specified amount into the account.
     *
     * Parameters  :
     *   amount - The monetary amount to deposit.
     *
     * Returns     : void
     *******************************************************************************/
    void deposit(double amount);

    /*******************************************************************************
     * Function    : withdraw
     * Description : Pure virtual function to withdraw funds from the account.
     *
     * Parameters  :
     *   amount - The monetary amount to withdraw.
     *
     * Returns     : void
     *******************************************************************************/
    virtual void withdraw(double amount) = 0;

    /*******************************************************************************
     * Function    : getType
     * Description : Pure virtual function to get the account type name.
     *
     * Parameters  : None.
     *
     * Returns     : string - Name of the account type.
     *******************************************************************************/
    virtual string getType() = 0;

    /*******************************************************************************
     * Function    : save
     * Description : Virtual function to serialize account details for file persistence.
     *
     * Parameters  : None.
     *
     * Returns     : string - Formatted account data for saving.
     *******************************************************************************/
    virtual string save(); // for file
};
