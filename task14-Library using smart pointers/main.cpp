#include <iostream>
#include <memory>
#include "Library.h"
#include "Book.h"
#include "User.h"

using namespace std;

int main() {
    Library lib;

    auto b1 = std::make_shared<Book>("Clean Code", "Robert C. Martin", 101);
    auto b2 = std::make_shared<Book>("C++ Primer", "Stanley B. Lippman", 102);

    auto u1 = std::make_shared<Student>("Samar", 1);
    auto u2 = std::make_shared<Teacher>("Dr. Ahmed", 2);
    auto u3 = std::make_shared<Engineer>("Eng. Omar", 3);

    lib.add_book(b1);
    lib.add_book(b2);

    lib.add_user(u1);
    lib.add_user(u2);
    lib.add_user(u3);

    lib.display_books();
    lib.display_users();

    cout << " Borrowing Test \n";
    b1->borrow_book();
    lib.display_books();

    return 0;
}
}
