#include "20250326.h"

template <typename T>
T sum(T a, T b) {
	return a + b;
}

int nsum(int a, int b, int c)
{
	return a + b + c;
}

double nsum(double a, double b)
{
	return a + b;
}

int nsum(int a, int b)
{
	return a + b;
}

template <typename Radius>
class Doughnut {
private:
	Radius radius;
public:
	Doughnut(Radius radius = 6) { this->radius = radius; };
	~Doughnut() { cout << "Someone ate a doughnut which size was " << this->radius << " cm long." << endl; }
	double getArea();
};

template <typename Radius>
double Doughnut<Radius>::getArea() {
	double area = this->radius * this->radius * 3.1415;
	return area;
}

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

int tuto0326()
{
	//템플릿
	int a = 1, b = 2;

	double d1 = 2.2;
	double d2 = 3.3;

	string s1 = "sm";
	string s2 = "tm";

	cout << "int 합 : " << sum<int>(a, b) << endl;
	cout << "double 합 : " << sum<double>(d1, d2) << endl;
	cout << "string 합 : " << sum<string>(s1, s2) << endl;

	//함수 중복
	int fa = nsum(3, 4, 5);
	double fb = nsum(7.48, 2.97);
	int fc = nsum(4, 20);

	cout << fa << endl;
	cout << fb << endl;
	cout << fc << endl;

	//제네릭클래스
	Doughnut<int> exampleDoughnutA(6);
	Doughnut<double> exampleDoughnutB(6.5);

	cout << exampleDoughnutA.getArea() << " square cm" << endl;
	cout << exampleDoughnutB.getArea() << " square cm" << endl;

	//클래스 상속
	Dog dog;
	dog.eat();
	dog.bark();

	return 0;
}