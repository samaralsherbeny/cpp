#pragma once
class Borrowable {
public:
    virtual void borrow_book() = 0;
    virtual void return_book() = 0;
    virtual bool check_availability() const = 0;
    virtual ~Borrowable() = default;
};

