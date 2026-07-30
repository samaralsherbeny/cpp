🏦 Bank Management System (C++)
📌 Overview
This project is a Bank Management System implemented in C++ using Object-Oriented Programming (OOP) principles.  
It simulates real-world banking operations such as account creation, deposits, withdrawals, transfers, and file storage.
The system is designed with abstraction, inheritance, polymorphism, and smart pointers to ensure clean and maintainable code.
---
🎯 Features
Create new accounts (Checking / Savings)
Deposit money
Withdraw money with validation
Transfer money between accounts
Prevent duplicate account IDs
Display all accounts
Save accounts to file
Load accounts from file
Exception handling for invalid operations
---
🧱 Project Structure
cpp project/
│
├── Account.h / Account.cpp
├── CheckingAccount.h / CheckingAccount.cpp
├── SavingsAccount.h / SavingsAccount.cpp
├── Bank.h / Bank.cpp
├── main.cpp
└── data.txt
---
🧩 OOP Concepts Used
Abstraction
Account is an abstract base class:
virtual void withdraw(double amount) = 0;
virtual string getType() const = 0;
Inheritance
CheckingAccount and SavingsAccount inherit from Account.
Polymorphism
Using shared_ptr<Account> for dynamic behavior.
Encapsulation
Data is protected and accessed using getters.
---
⚙️ Build & Run Instructions
Requirements
C++ compiler (g++)
C++11 or later
Compile
g++ -std=c++11 main.cpp Account.cpp Bank.cpp CheckingAccount.cpp SavingsAccount.cpp -o bank
Run
./bank
---
🧪 Validation Rules
Deposit: amount > 0  
Withdraw: amount > 0 and <= balance  
Create Account: unique ID, name not empty, balance >= 0  
Transfer: valid accounts and amount > 0
---
💾 File Handling
Data is stored in data.txt
Example:
Checking,1,Ali,1000
Savings,2,Sara,2000
Program loads on start and saves before exit.
---
⚠️ Error Handling
Uses exceptions:
invalid_argument
runtime_error
Example:
if (amount <= 0)
throw invalid_argument("Invalid deposit");
---
