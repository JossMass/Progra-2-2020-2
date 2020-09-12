#pragma once
#include <vector>
#include "Eclipse.h"

class ArrEclipse {
private:
	vector<Eclipse*> arr;

public:
	ArrEclipse(){}
	~ArrEclipse() {}

	//CRUD
	//Create / Read / Update / Delete

	void addEclipse() {
		Eclipse* e = new Eclipse();
		arr.push_back(e);
	}

	void insertEclipse(int position) {
		Eclipse* e = new Eclipse();
		arr.insert(arr.begin() + position, e);
	}

	void editEclipseType(int position, string newType) {
		arr.at(position)->setType(newType);
	}

	void deleteEclipse(int position) {
		arr.erase(arr.begin() + position);
	}

	void deleteLastEclipse() {
		arr.pop_back();
	}

	void printArray() {
		for (int i = 0; i < arr.size(); i++) {
			cout << endl;
			cout << "Eclipse " << i << endl;
			//arr.at(i)->printData();
			arr[i]->printData();
		}
	}

	void eclipsesVisiblesEurope() {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i]->getVisibility() == "Europe") {
				arr[i]->printData();
			}
		}
	}

	void eclipsesEarthquakes() {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i]->getEarthquake() == "Yes") {
				arr[i]->printData();
			}
		}
	}

	void eclipsesInTheNight() {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i]->getHour() >= 18) {
				arr[i]->printData();
			}
		}
	}
};