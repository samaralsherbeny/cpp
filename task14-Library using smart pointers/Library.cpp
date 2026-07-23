#include "Library.h"
#include <iostream>

void Library::add_book(std::shared_ptr<Book> b) {
    books.push_back(b);
    std::cout << "Added new book to library.\n";
}

void Library::add_user(std::shared_ptr<User> u) {
    users.push_back(u);
    std::cout << "Added new user to library.\n";
}

void Library::display_books() const {
    std::cout << "Library Books \n";
    for (const auto& b : books) {
        b->display_book_info();
    }
}

void Library::display_users() const {
    std::cout << " Library Users \n";
    for (const auto& u : users) {
        u->display_info();
    }
}
