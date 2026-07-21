#include<iostream>
#include<string>
using namespace std;
class Geometric
{
protected:
	float dim1;
	float dim2;
public:
	Geometric() {
		dim1 = 0;
		dim2 = 2;
		cout << "Geometric constructor\n";
	}
	Geometric(float dim1, float dim2) {
		this->dim1 = dim1;
		this->dim2 = dim2;
		cout << "Geometriic constructor\n";
	}
	virtual float getArea() {
		cout << "Geometric Area\n";
		return 0.0;
	}
	~Geometric() {
		cout << "Geometric destructor\n";
	}
};
class Triangle : public Geometric {
public:
	Triangle() :Geometric() {
		cout << "default constructor of Triangle class\n";
	}
	Triangle(float dim1, float dim2) : Geometric(dim1, dim2) {
		cout << "parametrized Triangle constructor\n";
	}
	float getArea() {
		cout << "Triangle Area: " << 0.5 * dim1 * dim2 << endl;
		return 0.5 * dim1 * dim2;
	}
	~Triangle() {
		cout << "Triangle destructor\n";
	}
};
	class Rectangle :public Geometric {
	public:
		Rectangle() :Geometric() {
			cout << "default constructor of Rectangle class\n";
		}
		Rectangle(float dim1, float dim2) :Geometric(dim1, dim2) {
			cout << "parametrized constructor of Rectangle class\n";
		}
		float getArea() {
			cout << "Rectangle Area: " << dim1 * dim2 << endl;
			return dim1 * dim2;
		}
		~Rectangle() {
			cout << "Rectangle destructor\n";
		}
	};
	class Square :public Rectangle{
	public:
		Square() :Rectangle() {
			cout << "default constructor of Square class\n";
		}
		Square(float dim) :Rectangle(dim, dim) {
			cout << "parametrized Square constructor\n";
		}
		float getArea() {
			cout << "Square Area: " << dim1 * dim2 << endl;
			return dim1 * dim2;
		}
		~Square() {
			cout << "Square destructor\n";
		}
   };
	int main() {
		Triangle t(20, 15);
		Rectangle r(6, 5);
		Square s(9);
		cout << t.getArea() << endl;
		cout << r.getArea() << endl;
		cout << s.getArea() << endl;
		Geometric* ptr = &t;
		ptr->getArea();
		return 0;
	}
