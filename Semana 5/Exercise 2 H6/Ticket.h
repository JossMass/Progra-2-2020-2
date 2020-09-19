#pragma once
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Ticket {
protected:
	int code;
	double price;
	Date date;

public:
	Ticket() {
		//cout << "Constructor Ticket" << endl;
		code = rand() % 9999999;
		price = rand() % 100000;
	}

	~Ticket(){}

	int getDay() { return date.getDay(); }
	int getMonth() { return date.getMonth(); }
	int getYear() { return date.getYear(); }

	void getInfoTicket() {
		cout << "Code: " << code << endl;
		cout << "Price: " << price << endl;
		cout << "Date: " << date.getCompleteDate() << endl;
	}

};