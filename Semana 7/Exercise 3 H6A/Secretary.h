#pragma once
#include "Employee.h"

class Secretary : public Employee {
private:
	int officeNumber;
	int faxNumber;

public:
	Secretary(){}
	Secretary(string name, string lastName, int DNI, string address, int phone, double salary) :
		Employee(name, lastName, DNI, address, phone, salary) {
		officeNumber = rand() % 101;
		faxNumber = rand() % 9000 + 1000;
		incrementPercentage = 5;
	}
	~Secretary(){}

	void getSecretaryInfo() {
		getEmployeeInfo();
		cout << "Office Number: " << officeNumber << endl;
		cout << "Fax Number: " << faxNumber << endl;
	}

	void getSupervisorInfo() {
		supervisor->getEmployeeInfo();
	}
};