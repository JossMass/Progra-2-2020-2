#pragma once
#include <iostream>
#include <string>

#include "Hotel.h"
#include "Ticket.h"

using namespace std;

class VacationPlan : public Hotel, public Ticket {
private:
	int duration;
	int numberOfPeople;

public:
	VacationPlan() {
		//cout << "Constructor Vacation Plan" << endl;
		duration = 1 + rand() % 15;
		numberOfPeople = 2 + rand() % 9;
	}

	~VacationPlan(){}

	void getInfoVacationPlan() {
		cout << "Duration: " << duration << endl;
		cout << "Number of people: " << numberOfPeople << endl;
		getInfoTicket();
		getInfoHotel();
		cout << endl;
	}
};