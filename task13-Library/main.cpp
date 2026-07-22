#include <iostream>
#include "Library.h"
#include "Book.h"
#include "User.h"

using namespace std;

int main() {
    Library lib;

    Book b1("Clean Code", "Robert C. Martin", 101);
    Book b2("C++ Primer", "Stanley B. Lippman", 102);

    Student u1("Samar", 1);
    Teacher u2("Dr. Ahmed", 2);
    Engineer u3("Eng. Omar", 3);

    lib.add_book(&b1);
    lib.add_book(&b2);

    lib.add_user(&u1);
    lib.add_user(&u2);
    lib.add_user(&u3);

    lib.display_books();
    lib.display_users();

    cout << " Borrowing Test \n";
    b1.borrow_book();
    lib.display_books();

    return 0;
}
