#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

double getPositiveDouble(string msg) {
	double value;
	while (true) {
		cout << msg;
		if (cin >> value && value >= 0)
			return value;
		cout << "invalid value , please try again \n";
		cin.clear();
		cin.ignore(100, '\n');
	}
}

int getPositiveInt (string msg) {
	int value;
	while (true) {
		cout << msg;
		if (cin >> value && value >= 0)
			return value;
		cout << "invalid value , please try again \n";
		cin.clear();
		cin.ignore(100, '\n');
	}
}

double calculateSalary(double hrs, double rate) {
	return hrs * rate;
}

double calculateSalary(double hrs, double rate, double overtime) {
	return (hrs * rate) + (overtime * rate * 2.5);
}

double calculateTax(double salary, double taxRate = 15) {
	return salary * taxRate / 100;
}

double addBonus(double salary, double bonus = 120) {
	return salary + bonus;
}

bool isManager(char position) {
	return tolower(position);
}

void printEmployeeInfo(string name, int id) {
	cout << "Employee: " << name << endl;
	cout << "ID: " << id << endl;
}

int main() {
	string name;
	int id;
	double salary;
	double hrs;
	double rate;
	char position;
	char bonusAnswer;
	cout << "Employee name: ";
	getline(cin, name);
	id = getPositiveInt("Employee ID: ");
	hrs = getPositiveDouble("Working Hrs: ");
	rate = getPositiveDouble("Hourly Rate: ");
	cout << "Position (m = manager , e = employee): ";
	cin >> position;
	position = tolower(position);

	while (position != 'm' && position != 'e') {
		cout << "invalid position , enter m or e : ";
		cin >> position;
		position = tolower(position);
	}

	if (isManager(position)) {
		double overtime;
		overtime = getPositiveDouble("Overtime Hrs : ");
		salary = calculateSalary(hrs, rate, overtime);
	}
	else
	{
		salary = calculateSalary(hrs, rate);
	}
	cout << fixed << setprecision(3);
	cout << "\n salary before tax : " << salary << "$" << endl;
	cout << "\n Add bonus? (y/n): ";
	cin >> bonusAnswer;
	bonusAnswer = tolower(bonusAnswer);
	
	while (bonusAnswer != 'y' && bonusAnswer != 'n') {
		cout << "invalid choice , enter (y/n): ";
		cin >> bonusAnswer;
		bonusAnswer = tolower(bonusAnswer);
	}

	if (bonusAnswer == 'y') {
		salary = addBonus(salary);
		cout << "bonus added. \n";
	}
	double tax = calculateTax(salary);
	salary -= tax;
	cout << "=========PayRoll========\n";
	cout << "Employee: " << name << "\n";
	cout << "ID : " << id << "\n";
	cout << "TAX: " << tax << " $\n";
	cout << "Final Salary: " << salary << " $\n";

	return 0;
}
