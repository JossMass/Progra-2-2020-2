#include <iostream>
#include <conio.h>
#include <ctime>
#include "HotelArray.h"

int main() {
	srand(time(NULL));

	HotelArray* arr = new HotelArray(5);
	arr->addHotel();
	arr->addHotel();
	arr->addHotel();
	arr->printData();

	/*cout << "----------------------------------" << endl;
	cout << "HOTEL REMOVED " << endl << endl;
	arr->removeHotel(1);
	arr->printData();*/
	/*cout << "----------------------------------" << endl;
	cout << "HOTEL EDITED " << endl << endl;
	arr->editHotelName("ChorrillosHotel", 0);
	arr->printData();*/
	cout << "----------------------------------" << endl;
	cout << "HOTEL CAMPOS ELISEOS " << endl << endl;
	arr->printCamposEliseos();
	cout << "----------------------------------" << endl;
	cout << "HOTEL BREAKFAST" << endl << endl;
	arr->printBreakfast();
	cout << "----------------------------------" << endl;
	cout << "HOTEL AIRPORTSERVICE" << endl << endl;
	arr->printAirportService();

	_getch();
	return 0;
}