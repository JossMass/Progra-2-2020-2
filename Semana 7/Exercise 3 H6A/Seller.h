#pragma once
#include "Employee.h"
#include "Car.h"
#include <vector>

class Seller : public Employee {
private:
	Car car;
	vector<Person*> clients;
	int commissionPercentage;

public:
	Seller(){}
	Seller(string name, string lastName, int DNI, string address, int phone, double salary) :
		Employee(name, lastName, DNI, address, phone, salary) {
		commissionPercentage = 15;
		incrementPercentage = 10;
	}

	void addClient(Person* p) {
		clients.push_back(p);
	}

	void removeClient() {
		clients.pop_back();
	}

	void setNewCar() {
		car = Car();
	}

	void getSellerInfo() {
		getEmployeeInfo();
		cout << "This is my car information: " << endl;
		car.getCarInfo();
		cout << "Commission percentage: " << commissionPercentage << endl;
		cout << "Number of clients: " << clients.size() << endl;
	}
};