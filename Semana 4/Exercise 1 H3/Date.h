#pragma once
#include <string>

using namespace std;

class Date {
private:
	int d, m, y;

public:
	Date() {
		d = rand() % 30 + 1;
		m = rand() % 12 + 1;
		y = rand() % 11 + 2010;
	}

	~Date(){}

	string getCompleteDate() {
		//dd/mm/yy
		string aux;
		aux.append(to_string(d));
		aux.append("/");
		aux.append(to_string(m));
		aux.append("/");
		aux.append(to_string(y));

		return aux;
	}
};