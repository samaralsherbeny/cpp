#pragma once
#include <string>
#include "Borrowable.h"

class Book : public Borrowable {
private:
    std::string title;
    std::string author;
    int book_id;
    bool isAvailable;

public:
    Book(std::string title, std::string author, int book_id);

    void borrow_book() override;
    void return_book() override;
    bool check_availability() const override;

    void display_book_info() const;
    int getId() const;
};
