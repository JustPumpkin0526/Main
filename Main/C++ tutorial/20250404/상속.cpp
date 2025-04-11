#include "»ó¼Ó.h"

class Animal {
public:
	void eat() {
		cout << "Eating..." << endl;
	}
};

class Dog : public Animal {
public:
	void bark() {
		cout << "Barking..." << endl;
	}
};

class Base1 {
public:
	void function1() {
		std::cout << "Base1 function1" << std::endl;
	}
};

class Base2 {
public:
	void function2() {
		std::cout << "Base2 function2" << std::endl;
	}
};

class Derived : public Base1, public Base2 {
};

class Shape {
public:
	virtual double getArea() = 0;
};

class Circle : public Shape {
private:
	double radius;
public:
	Circle(double r) : radius(r) {}
	double getArea() override {
		return 3.14 * radius * radius;
	}
};

class Rectangle : public Shape {
private:
	double width, height;
public:
	Rectangle(double w, double h) : width(w), height(h) {}
	double getArea() override {
		return width * height;
	}
};

int der() {

	Shape* shapes[2];
	shapes[0] = new Circle(3.0);
	shapes[1] = new Rectangle(3.0, 4.0);

	for (int i = 0; i < 2; ++i) {
		std::cout << "Area of shape " << i + 1 << " = " << shapes[i]->getArea() << "\n";
	}

	delete shapes[0];
	delete shapes[1];

	Dog dog;
	dog.eat();
	dog.bark();

	Derived d;
	d.function1();
	d.function2();

	return 0;
}