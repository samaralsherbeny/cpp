#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int math;
    int physics;
    int english;
    double calculateAverage() const {
        return (math + physics + english) / 3.0;
    }

    char calculateGrade(double average) const {
        if (average >= 90) return 'A';
        else if (average >= 80) return 'B';
        else if (average >= 70) return 'C';
        else if (average >= 60) return 'D';
        else return 'F';
    }

public:
    Student(string studentName) {
        this->name = studentName;
    }

    void inputMarks() {
        cout << "Enter Math mark: ";
        cin >> math;
        cout << "Enter Physics mark: ";
        cin >> physics;
        cout << "Enter English mark: ";
        cin >> english;
    }
    void printReport() const {
        double avg = calculateAverage();
        char grade = calculateGrade(avg);

        cout << "\n--- Student Report ---\n";
        cout << "Name: " << name << endl;
        cout << "Math: " << math << endl;
        cout << "Physics: " << physics << endl;
        cout << "English: " << english << endl;
        cout << "Average: " << avg << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    string name;
    int choice;

    cout << "Enter student name: ";
    getline(cin, name);

    Student student(name);

    student.inputMarks();

    do {
        cout << "\nMenu:\n";
        cout << "1. Print Report\n";
        cout << "2. Update Marks\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            student.printReport(); 
            break;
        case 2:
            student.inputMarks(); 
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
