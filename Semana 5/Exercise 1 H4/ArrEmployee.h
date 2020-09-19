#pragma once
#include <vector>
#include "Employee.h"

class ArrEmployee {
private:
	vector<Employee*> arr;

public:
	ArrEmployee(){}
	~ArrEmployee() {}

	void addEmployee(Employee* e) {
		arr.push_back(e);
	}

	void listAll() {
		for (int i = 0; i < arr.size(); i++) {
			arr[i]->printData();
		}
	}

	void employeesBornInApril() {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i]->getBirthMonth() == 4) {
				arr[i]->printData();
			}
		}
	}

	int employeesMarch2017() {
		int c = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i]->getHiringMonth() == 3 && arr[i]->getHiringYear() == 2017) {
				c++;
			}
		}
		return c;

	}
};