#include "20250325.h"

class Car {
public:
	string color;
	string model;
	string manufacturer;

	void drive() {
		cout << "차 운전 실행" << endl;
	}

	void stop() {
		cout << "차 멈춤" << endl;
	}

	void info() {
		cout << "color is " << this->color << endl;
		cout << "model is " << this->model << endl;
		cout << "manufacturer is " << this->manufacturer << endl;
	}
};

class Student
{
	string name;
	int age;
	double grade;
public:

	Student(string n, int a, double g) : name(n), age(a), grade(g) {
		cout << "a Student " << name << " is created" << endl;
	}

	~Student() {
		cout << "a Student " << name << " is destroyed" << endl;
	}

	void study() {
		grade += 0.1;
	}

};

class Person {
	string name;
	int age;

public:
	// 생성자에서 멤버 초기화 리스트 사용
	Person(string n, int a) : name(n), age(a) {}

	void print() {
		cout << "이름: " << name << ", 나이: " << age << endl;
	}
};

class thst
{
	int id;

public:
	void setID(int id) {
		this->id = id;
	}
	int getID() {
		return this->id;
	}
};

int tuto0325()
{

	//클래스 생성
	Car myCar;
	Car yourCar;

	myCar.color = "Red";
	myCar.model = "Sedan";
	myCar.manufacturer = "hyundai";

	yourCar.color = "blue";
	yourCar.model = "abante";
	yourCar.manufacturer = "toyota";

	myCar.info();

	yourCar.info();

	//클래스 생성자 소멸자
	Student student1("john", 20, 3.5);
	student1.study();

	//클래스 멤버 초기화 리스트
	Person p("Alice", 25);
	p.print();
	return 0;

	//클래스 객체 생성
	Student* student2 = new Student("John", 20, 3.5);
	delete student2;

	//클래스 this 포인터
	thst stu;
	stu.setID(123);
	cout << "Student ID: " << stu.getID() << endl;
}