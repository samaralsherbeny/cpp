#pragma once
#include <vector>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<Book*> books;
    std::vector<User*> users;

public:
    void add_book(Book* b);
    void add_user(User* u);
    void display_books() const;
    void display_users() const;
};
