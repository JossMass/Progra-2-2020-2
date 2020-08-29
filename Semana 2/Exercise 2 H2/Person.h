#pragma once
#include <string>
#include <iostream>


using namespace std;

class Person {
private:
	string name;
	int DNI;
	char gender;
	int age;
	double height;
	double weight;

public:
	Person(){}
	Person(string name, int age, char gender) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		height = rand() % 3;
		weight = rand() % 100;
		generateDNI();
	}

	Person(string name, int age, char gender, double height, double weight) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->height = height;
		this->weight = weight;	
		generateDNI();
	}

	int calculateIMC() {
		double result = weight / (height * height);
		if (result < 20) {
			return -1;
		}
		else if (result > 20 && result <= 25) {
			return 0;
		}
		else if (result > 25) {
			return 1;
		}
	}

	bool isLegalAge() {
		if (age >= 18) return true;
		else return false;
	}

	void checkGender() {
		if (gender != 'M' && gender != 'F') {
			gender = 'M';
		}
	}

	void getInformation() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Gender: " << gender << endl;
		cout << "Height: " << height << endl;
		cout << "Weight: " << weight << endl;
		cout << "DNI: " << DNI << endl;
	}

	void generateDNI() {
		DNI = 10000000 + rand() % 8000000;
	}

	void setHeight(double v) { height = v; }
	void setWeight(double v) { weight = v; }

};