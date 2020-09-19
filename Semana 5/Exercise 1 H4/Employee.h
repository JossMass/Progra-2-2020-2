#pragma once
#include "Date.h"

class Employee {
private:
	string name;
	string lastName;
	Date birthdate;
	Date hiringdate;
	
public:
	Employee(string name, string lastName, Date birthdate, Date hiringdate) {
		this->birthdate = birthdate;
		this->hiringdate = hiringdate;
		this->name = name;
		this->lastName = lastName;
	}

	int getBirthMonth() { return birthdate.getMonth(); }
	int getHiringMonth() { return hiringdate.getMonth(); }
	int getHiringYear() { return hiringdate.getYear(); }

	void printData() {
		cout << "Name: " << name << endl;
		cout << "Last Name: " << lastName << endl;
		cout << "Birthdate: "; birthdate.monthLetters(); cout << endl;
		cout << "Hiringdate: "; hiringdate.monthLetters(); cout << endl;
	}
};