#pragma once
#include <vector>
#include "VacationPlan.h"

class ArrVacationPlan {
private:
	vector<VacationPlan*> arr;

public:
	ArrVacationPlan() {}
	~ArrVacationPlan(){}

	void addVacationPlan() {
		VacationPlan* v = new VacationPlan();
		arr.push_back(v);
	}

	void deleteLastVacationPlan() {
		arr.pop_back();
	}

	void vacationPlanInAYearInterval(int by, int ay) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i]->getYear() >= by && arr[i]->getYear() <= ay) {
				arr[i]->getInfoVacationPlan();
			}
		}
	}

	void vacationPlanSameHotelName(string name) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i]->getName() == name) {
				arr[i]->getInfoVacationPlan();
			}
		}
	}

	void listAllTickets() {
		for (int i = 0; i < arr.size(); i++) {
			arr[i]->getInfoTicket();
		}
	}

	void listAllVacationPlan() {
		for (int i = 0; i < arr.size(); i++) {
			arr[i]->getInfoVacationPlan();
		}
	}


};