#include <iostream>
#include <string>
using namespace std;
class Vehicle {
protected:
	string type;
public:
	Vehicle() {
		type = "Generic Vehicle";
		cout << "Vehicle constructor\n";
	}
	Vehicle(string type) {
		this->type = type;
		cout << "Parameterized Vehicle constructor\n";
	}
	virtual void move() {
		cout << type << " is moving\n";
	}
	 ~Vehicle() {
		cout << "Vehicle destructor\n";
	}
};
class Car : public Vehicle {
public:
	Car() : Vehicle("Car") {
		cout << "default constructor of Car class\n";
	}

	Car(string type) : Vehicle(type) {
		cout << "parameterized constructor of Car class\n";
	}

	void move()  {
		cout << "Car is driving on roads\n";
	}

	~Car()  {
		cout << "Car destructor\n";
	}
};
class BMW : public Car {
public:
	BMW() : Car("BMW") {
		cout << "default constructor of BMW class\n";
	}

	void move()  {
		cout << "BMW is cruising at high speed on the highway!\n";
	}

	~BMW()  {
		cout << "BMW destructor\n";
	}
};
class Toyota : public Car {
public:
	Toyota() : Car("Toyota") {
		cout << "default constructor of Toyota class\n";
	}

	void move()  {
		cout << "Toyota is driving reliably through town\n";
	}

	~Toyota()  {
		cout << "Toyota destructor\n";
	}
};
class Plane : public Vehicle {
public:
	Plane() : Vehicle("Plane") {
		cout << "default constructor of Plane class\n";
	}

	void move()  {
		cout << "Plane is flying in the sky\n";
	}

	~Plane()  {
		cout << "Plane destructor\n";
	}
};
class Boeing : public Plane {
public:
	Boeing() : Plane() {
		cout << "default constructor of Boeing class\n";
	}

	void move()  {
		cout << "Boeing 747 is flying transatlantic at 30,000 feet\n";
	}

	~Boeing()  {
		cout << "Boeing destructor\n";
	}
};
class Truck : public Vehicle {
public:
	Truck() : Vehicle("Truck") {
		cout << "default constructor of Truck class\n";
	}

	void move() {
		cout << "Truck is hauling cargo\n";
	}

	~Truck() {
		cout << "Truck destructor\n";
	}
};
class MercedesTruck : public Truck {
public:
	MercedesTruck() : Truck() {
		cout << "default constructor of MercedesTruck class\n";
	}

	void move()  {
		cout << "Mercedes-Benz Actros truck is transporting heavy logistics\n";
	}

	~MercedesTruck()  {
		cout << "MercedesTruck destructor\n";
	}
};
class Motorcycle : public Vehicle {
public:
	Motorcycle() : Vehicle("Motorcycle") {
		cout << "default constructor of Motorcycle class\n";
	}

	void move()  {
		cout << "Motorcycle is weaving through traffic\n";
	}

	~Motorcycle()  {
		cout << "Motorcycle destructor\n";
	}
};
class HondaMotorcycle : public Motorcycle {
public:
	HondaMotorcycle() : Motorcycle() {
		cout << "default constructor of HondaMotorcycle class\n";
	}

	void move() {
		cout << "Honda CBR Motorcycle is accelerating fast!\n";
	}

	~HondaMotorcycle() {
		cout << "HondaMotorcycle destructor\n";
	}
};
int main() {
	BMW b;
	Toyota t;
	Boeing bo;
	MercedesTruck m;
	HondaMotorcycle h;
	b.move();
	t.move();
	bo.move();
	m.move();
	h.move();
	Vehicle* ptr = &b;
	ptr->move(); 
	return 0;
}
