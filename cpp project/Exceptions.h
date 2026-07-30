#pragma once
#include <stdexcept>
using namespace std;

class InsufficientBalanceException : public runtime_error {
public:
    InsufficientBalanceException() : runtime_error("Insufficient balance") {}
};

class AccountNotFoundException : public runtime_error {
public:
    AccountNotFoundException() : runtime_error("Account not found") {}
};

class DuplicateIDException : public runtime_error {
public:
    DuplicateIDException() : runtime_error("Account ID already exists") {}
};
