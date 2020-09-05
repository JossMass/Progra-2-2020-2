#pragma once
#include <iostream>
#include <string>

using namespace std;

string hotelLocations[7] = { "Isla de la Cite", "San Luis", "Barrio Latino","Montmartre", "La Defensa",
							"Campos Eliseos","Plaza de la Concordia" };

string hotelNames[7] = { "Marriot", "Shell", "Portman", "Winston", "Paris","Trivago","Casa Andina" };

class Hotel {
private:
	string name;
	int starts;
	string location;
	bool breakfast;
	int telephone;
	bool airportService;

public:
	Hotel() {
		name = hotelNames[rand() % 7];
		starts = rand() % 5 + 1;
		location = hotelLocations[rand() % 7];
		breakfast = rand() % 2;
		telephone = rand() % 800000 + 1000000;
		airportService = rand() % 2;
	}

	//Getters
	string getName() { return name; }
	int getStarts() { return starts; }
	string getLocation() { return location; }
	bool getBreakfast() { return breakfast; }
	int getTelephone() { return telephone; }
	bool getAirportService() { return airportService; }

	//Setter
	void setName(string v) { name = v; }
	void setStarts(int v) { starts = v; }
	void setLocation(string v) { location = v; }
	void setBreakfast(bool v) { breakfast = v; }
	void setTelephone(int v) { telephone = v; }
	void setAirportService(bool v) { airportService = v; }

	void getInformation() {
		cout << "Name: " << name << endl;
		cout << "Starts: " << starts << endl;
		cout << "Location: " << location << endl;
		cout << "Breakfast: ";
		if (breakfast) {
			cout << "YES" << endl;
		}
		else { cout << "NO" << endl; }
		cout << "Telephone: " << telephone << endl;
		cout << "Airport Service: ";
		if (airportService) {
			cout << "YES" << endl;
		}
		else { cout << "NO" << endl; }
		cout << endl;
	}
};