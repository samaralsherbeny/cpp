#include "User.h"
#include <iostream>

User::User(std::string name, int user_id) : name(name), user_id(user_id) {}

Student::Student(std::string name, int user_id) : User(name, user_id) {}
void Student::display_info() const {
    std::cout << "Student  | Name: " << name << " | ID: " << user_id << "\n";
}

Teacher::Teacher(std::string name, int user_id) : User(name, user_id) {}
void Teacher::display_info() const {
    std::cout << "Teacher  | Name: " << name << " | ID: " << user_id << "\n";
}

Engineer::Engineer(std::string name, int user_id) : User(name, user_id) {}
void Engineer::display_info() const {
    std::cout << "Engineer | Name: " << name << " | ID: " << user_id << "\n";
}
