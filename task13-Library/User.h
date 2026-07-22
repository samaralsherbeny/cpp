#pragma once
#include <string>

class User {
protected:
    std::string name;
    int user_id;

public:
    User(std::string name, int user_id);
    virtual void display_info() const = 0; 
    virtual ~User() = default;
};

class Student : public User {
public:
    Student(std::string name, int user_id);
    void display_info() const override;
};

class Teacher : public User {
public:
    Teacher(std::string name, int user_id);
    void display_info() const override;
};

class Engineer : public User {
public:
    Engineer(std::string name, int user_id);
    void display_info() const override;
};
 
