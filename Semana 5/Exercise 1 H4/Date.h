#pragma once
#include <string>
#include <iostream>

using namespace std;

string Months[12] = { "January","February","March","April","May","June","July",
"August","September","October","November","December" };

class Date {
private:
	int	day;
	int month;
	int year;

public:
	Date(){}
	Date(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	~Date(){}

	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }

	void setDay(int v) { day = v; }
	void setMonth(int v) { month = v; }
	void setYear(int v) { year = v; }

	string getCompleteDate() {
		//dd/mm/yy
		string aux;
		aux.append(to_string(day));
		aux.append("/");
		aux.append(to_string(month));
		aux.append("/");
		aux.append(to_string(year));

		return aux;
	}

	//Anio bisiesto tiene que ser multiplo de 4
	//Los anios que son multiplos de 100 no son bisiestos, salvo que aparte
	//de ser multiplos de 100 sean multiplos de 400

	bool leapYear() {
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))return true;
		else return false;
	}

	void monthLetters() {
		//7 of September, 2020
		cout << day << " of " << Months[month - 1] << ", " << year;
	}

	bool dateIsReal() {
		if (month >= 1 && month <= 12) {
			switch (month){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				if (day >= 1 && day <= 31) return true;
				else return false;
				break;

			case 4: case 6: case 9: case 11:
				if (day >= 1 && day <= 30) return true;
				else return false;
				break;
				
			case 2:
				if (leapYear()) {
					if (day >= 1 && day <= 29)return true;
					else return false;
				}
				else {
					if (day >= 1 && day <= 28)return true;
					else return false;
				}

			}
		}
		else {
			return false;
		}
	}
};