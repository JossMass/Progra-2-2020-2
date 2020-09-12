#pragma once
#include <iostream>
#include "Time.h"
#include "Date.h"

string Types[2] = { "Solar", "Lunar" };
string Announcements[2] = { "Yes", "No" };
string Continents[5] = { "South America", "North America", "Europe" , "Asia", "Africa" };

class Eclipse {
private:
	string type;
	Date date;
	Time time;
	string earthquake;
	string rain;
	string visibility;

public:
	Eclipse() {
		type = Types[rand() % 2];
		date = Date();
		time = Time();
		earthquake = Announcements[rand() % 2];
		rain = Announcements[rand() % 2];
		visibility = Continents[rand() % 5];
	}

	string getVisibility() { return visibility; }
	string getEarthquake() { return earthquake; }
	int getHour() { return time.getHour(); }
	void setType(string v) { type = v; }

	void printData() {
		cout << "Type: " << type << endl;
		cout << "Date: " << date.getCompleteDate() << endl;
		cout << "Time: " << time.getCompleteTime() << endl;
		cout << "Earthquake: " << earthquake << endl;
		cout << "Rain: " << rain << endl;
		cout << "Visibility: " << visibility << endl << endl;
	}
};