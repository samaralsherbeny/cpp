#include "Book.h"
#include <iostream>

Book::Book(std::string title, std::string author, int book_id)
    : title(title), author(author), book_id(book_id), isAvailable(true) {
}

void Book::borrow_book() {
    if (isAvailable) {
        isAvailable = false;
        std::cout << "Book '" << title << "' has been successfully borrowed.\n";
    }
    else {
        std::cout << "Sorry, '" << title << "' is currently unavailable.\n";
    }
}

void Book::return_book() {
    if (!isAvailable) {
        isAvailable = true;
        std::cout << "Book '" << title << "' has been returned.\n";
    }
    else {
        std::cout << "Book '" << title << "' was not borrowed.\n";
    }
}

bool Book::check_availability() const {
    return isAvailable;
}

void Book::display_book_info() const {
    std::cout << "[ID: " << book_id << "] " << title << " by " << author
        << " | Status: " << (isAvailable ? "Available" : "Borrowed") << "\n";
}

int Book::getId() const {
    return book_id;
}
