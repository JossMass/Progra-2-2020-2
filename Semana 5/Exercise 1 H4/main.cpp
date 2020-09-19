#include <conio.h>
#include "ArrEmployee.h"

using namespace std;
using namespace System;

void menu() {
	cout << "1. Add Employee" << endl;
	cout << "2. Employees born in April" << endl;
	cout << "3. Quantity of employees hired in march 2017" << endl;
	cout << "4. List all employees" << endl << endl;
}

int main() {
	int option;
	string name, lastName;
	int day, month, year;
	Date b;
	Date h;
	ArrEmployee* arr = new ArrEmployee();
	Employee* e;

	while (1) {
		menu();
		cout << "Enter the option: "; cin >> option;

		switch (option){
		case 1:
			cout << "Name: "; cin >> name;
			cout << "Last Name: "; cin >> lastName;
			do {
				cout << "Please enter the correct date" << endl;
				cout << "Birthdate day: "; cin >> day;
				cout << "Birthdate month: "; cin >> month;
				cout << "Birthdate year: "; cin >> year;
				b = Date(day, month, year);
			} while (!b.dateIsReal());

			do {
				cout << "Please enter the correct date" << endl;
				cout << "Hiringdate day: "; cin >> day;
				cout << "Hiringdate month: "; cin >> month;
				cout << "Hiringdate year: "; cin >> year;
				h = Date(day, month, year);
			} while (!h.dateIsReal());

			e = new Employee(name, lastName, b, h);
			arr->addEmployee(e);
			cout << "Employee added";
			break;

		case 2:
			arr->employeesBornInApril(); break;

		case 3:
			cout << "The number of employees hired in march 2017 are: " << arr->employeesMarch2017(); break;

		case 4: 
			arr->listAll(); break;
		}

		_getch();
		system("cls");
	}

	_getch();
	return 0;
}