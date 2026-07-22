# Task 13: Library Management System 📚

Welcome to my Library Management System! In this task, I implemented a full Object-Oriented Programming (OOP) system in C++ to practice key architectural concepts like **Abstract Classes**, **Interfaces**, **Polymorphism**, and **Aggregation**.

## 🧩 System Architecture & Class Breakdown

Here is a breakdown of the classes I created for this system and what each one does:

### 1. `Borrowable` Class (Interface)
I created this as a pure abstract class (interface) to define a clear contract for any item in the library that can be checked out. It enforces three main pure virtual functions:
* `borrow_book()`: Handles borrowing logic.
* `return_book()`: Handles returning logic.
* `check_availability()`: Returns whether the item is currently available.

### 2. `Book` Class
This class implements the `Borrowable` interface. It represents individual books in the system and stores private attributes like `title`, `author`, `book_id`, and `isAvailable`. I implemented the borrowing logic here so that a book's availability status updates dynamically when borrowed or returned.

### 3. `User` Class (Abstract Base Class)
I designed `User` as an abstract base class to hold common member attributes for anyone using the library (`name` and `user_id`). It features a pure virtual method `display_info()`, forcing every specific type of user to define how their details are printed.

### 4. User Subclasses (`Student`, `Teacher`, `Engineer`)
These classes inherit directly from my `User` base class. Each one overrides `display_info()` to print the user's specific role alongside their name and ID. This structure makes it easy if I want to add role-specific privileges later!

### 5. `Library` Class
This is the central manager of the system. I used **Aggregation** here by storing dynamic collections (`std::vector`) of pointers to `Book` and `User` objects. It provides methods like `add_book()`, `add_user()`, `display_books()`, and `display_users()` to manage all library resources in one place without owning their lifetimes directly.
