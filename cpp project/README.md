# 🏦 Banking System (OOP-Based Project)

## 📌 Overview
This project is a simple banking system implemented using Object-Oriented Programming (OOP) concepts in C++. It supports account management, transactions, file handling, and exception handling.

---

## 🧠 OOP Concepts Used

### 🔹 Encapsulation
- Account data (`id`, `name`, `balance`) is kept private.
- Access is controlled through public getter methods.
- Ensures data safety and controlled modification.

### 🔹 Inheritance
- `CheckingAccount` and `SavingsAccount` inherit from the base class `Account`.
- Promotes code reuse and logical hierarchy.

### 🔹 Polymorphism
- Functions like `withdraw()` and `getType()` are overridden in derived classes.
- Allows different behavior depending on account type.

### 🔹 Abstraction
- `Account` is an abstract class.
- Defines a common structure while hiding implementation details.

---

## 📌 Features

- Create accounts (Savings / Checking)
- Deposit money
- Withdraw money
- Transfer between accounts
- Display all accounts
- Persistent storage using file system
- Exception handling for:
  - Duplicate account IDs
  - Account not found
  - Insufficient balance

---

## 🏗️ Project Structure

```
├── main.cpp
├── Bank.h / Bank.cpp
├── Account.h / Account.cpp
├── SavingsAccount.h / SavingsAccount.cpp
├── CheckingAccount.h / CheckingAccount.cpp
├── Exceptions.h
├── data.txt (auto-generated)
```

---

### 📄 File Descriptions

- **main.cpp**  
  Entry point of the program. Handles user interaction.

- **Account**  
  Abstract base class containing common properties and methods.

- **CheckingAccount / SavingsAccount**  
  Derived classes implementing specific behaviors.

- **Bank**  
  Manages all accounts and operations like deposit, withdraw, and transfer.

- **Exceptions.h**  
  Contains custom exception classes.

- **data.txt**  
  Stores account data for persistence.

---

## ⚠️ Exception Handling

The system handles the following exceptions:

### 🔴 1. Insufficient Balance
- Exception: `InsufficientBalanceException`
- Triggered when withdrawing more than available balance.

### 🔴 2. Account Not Found
- Exception: `AccountNotFoundException`
- Triggered when an account ID does not exist.

### 🔴 3. Duplicate Account ID
- Exception: `DuplicateIDException`
- Triggered when trying to create an account with an existing ID.

---

## ▶️ How to Use

After running the program, you will see a menu:

```
1. Create Account
2. Deposit
3. Withdraw
4. Transfer
5. Show Accounts
0. Exit
```

### Example Usage

- Create account → choose type (Savings / Checking)  
- Deposit money → enter ID + amount  
- Withdraw → system checks balance automatically  
- Transfer → moves money between accounts  

---

## 💾 Data Persistence

- All accounts are saved in:
  ```
  data.txt
  ```
- Data is automatically:
  - Loaded at program start  
  - Saved when exiting  

---

## ⚠️ Error Handling

The system uses custom exceptions:

- `DuplicateIDException`
- `AccountNotFoundException`
- `InsufficientBalanceException`

All errors are handled safely using `try/catch`.

---

## 🔷 UML Diagram 

<img width="1438" height="866" alt="image" src="https://github.com/user-attachments/assets/5c215160-123f-4351-9766-78c205bb4c9c" />

---
## ⭐ Notes

This project demonstrates:
- Object-Oriented Programming (OOP)
- File Handling
- Exception Handling
- Smart Pointers (`shared_ptr`)
- Clean and modular code structure

## 🚀 Conclusion

This project demonstrates the use of core OOP principles to build a modular, maintainable, and scalable banking system. It also integrates file handling and exception handling to ensure reliability.


