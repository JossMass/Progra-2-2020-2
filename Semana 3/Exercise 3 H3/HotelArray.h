#pragma once
#include "Hotel.h"

class HotelArray {
private:
	Hotel** arr;
	int n;
	int index;

public:

	HotelArray(int n) {
		this->n = n;
		index = 0;
		arr = new Hotel * [n];
	}

	~HotelArray() {}

	//CRUD Operations
	//Create / Read / Update / Delete

	void addHotel() {
		if (index < n) {
			Hotel* h = new Hotel();
			arr[index] = h;
			index++;
		}
	}

	void editHotelName(string newName, int position) {
		for (int i = 0; i < index; i++) {
			if (i == position) {
				arr[i]->setName(newName);
			}
		}
	}

	void removeHotel(int position) {
		for (int i = 0; i < index; i++) {
			if (i == position) {
				for (int j = position; j < index; j++) {
					arr[j] = arr[j + 1];
				}
			}
		}
		index--;
	}

	void printData() {
		for (int i = 0; i < index; i++) {
			cout << "Hotel: " << i << endl;
			arr[i]->getInformation();
		}
	}

	void printCamposEliseos() {
		for (int i = 0; i < index; i++) {
			if (arr[i]->getLocation() == "Campos Eliseos") {
				arr[i]->getInformation();
			}
		}
	}

	void printBreakfast() {
		for (int i = 0; i < index; i++) {
			if (arr[i]->getBreakfast()) {
				arr[i]->getInformation();
			}
		}
	}

	void printAirportService() {
		for (int i = 0; i < index; i++) {
			if (arr[i]->getAirportService()) {
				arr[i]->getInformation();
			}
		}
	}


};