#pragma once
#include "Person.h"

class Employee : public Person {
protected:
	int yearsWorked;
	int phone;
	double salary;
	double incrementPercentage;
	Employee* supervisor;

public:
	Employee(){}
	Employee(string name, string lastName, int DNI, string address, int phone, double salary) :
		Person(name, lastName, DNI, address) {
		this->phone = phone;
		this->salary = salary;
		yearsWorked = rand() % 20;
		supervisor = NULL;
		incrementPercentage = NULL;
	}
	~Employee(){}

	void getEmployeeInfo() {
		getPersonInfo();
		cout << "Years Worked: " << yearsWorked << endl;
		cout << "Phone: " << phone << endl;
		cout << "Salary: " << salary << endl;
		if (supervisor != NULL) {
			cout << "Supervisor: " << supervisor->getName() << endl;
		}
	}

	void setSupervisor(Employee* newSupervisor) {
		supervisor = newSupervisor;
	}

	void increaseSalary() {
		salary += double(incrementPercentage) / 100 * salary;
	}
};