#pragma once
#include <iostream>
#include <string>

using namespace std;

string Continents[5] = { "North America", "South America", "Europe","Asia","Africa" };
string Names[5] = { "Marriot","Westin","Perkin","BigHouse","Landing" };
string Types[4] = { "Bussiness","Airport","Suite","Resort" };

class Hotel {
protected:
	string name;
	string location;
	string type;
	int stars;

public:
	Hotel() {
		//cout << "Constructor Hotel" << endl;
		location = Continents[rand() % 5];
		type = Types[rand() % 4];
		name = Names[rand() % 5];
		stars = rand() % 6;
	}

	string getName() { return name;}
	string getLocation() { return location; }
	string getType() { return type; }
	int getStars() { return stars; }

	void getInfoHotel() {
		cout << "Name: " << name << endl;
		cout << "Location: " << location << endl;
		cout << "Type: " << type << endl;
		cout << "Stars: " << stars << endl;
	}

};