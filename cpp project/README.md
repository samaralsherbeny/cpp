# 💳 Simple Bank System (C++)

A console-based banking system written in C++ that allows users to create and manage bank accounts, perform transactions, and store data persistently using file handling.

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

## ⚙️ Requirements

- C++ Compiler (supports C++11 or higher)
  - g++ (MinGW / Linux / Mac)
  - OR Visual Studio (recommended on Windows)

---

## 🛠️ Build Instructions

### 🔹 Using g++ (Terminal / VS Code)

1. Open terminal in project folder

2. Compile all files:

```bash
g++ main.cpp Bank.cpp Account.cpp SavingsAccount.cpp CheckingAccount.cpp -o bank
```

3. Run the program:

```bash
./bank
```
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
## ⭐ Notes

This project demonstrates:
- Object-Oriented Programming (OOP)
- File Handling
- Exception Handling
- Smart Pointers (`shared_ptr`)
- Clean and modular code structure
