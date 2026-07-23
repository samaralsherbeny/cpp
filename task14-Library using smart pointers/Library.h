#pragma once
#include <vector>
#include <memory>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<std::shared_ptr<Book>> books;
    std::vector<std::shared_ptr<User>> users;

public:
    void add_book(std::shared_ptr<Book> b);
    void add_user(std::shared_ptr<User> u);
    void display_books() const;
    void display_users() const;
};
