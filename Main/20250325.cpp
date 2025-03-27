#include "20250325.h"

class Car {
public:
	string color;
	string model;
	string manufacturer;

	void drive() {
		cout << "�� ���� ����" << endl;
	}

	void stop() {
		cout << "�� ����" << endl;
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
	// �����ڿ��� ��� �ʱ�ȭ ����Ʈ ���
	Person(string n, int a) : name(n), age(a) {}

	void print() {
		cout << "�̸�: " << name << ", ����: " << age << endl;
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

	//Ŭ���� ����
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

	//Ŭ���� ������ �Ҹ���
	Student student1("john", 20, 3.5);
	student1.study();

	//Ŭ���� ��� �ʱ�ȭ ����Ʈ
	Person p("Alice", 25);
	p.print();
	return 0;

	//Ŭ���� ��ü ����
	Student* student2 = new Student("John", 20, 3.5);
	delete student2;

	//Ŭ���� this ������
	thst stu;
	stu.setID(123);
	cout << "Student ID: " << stu.getID() << endl;
}