#pragma once
#include <string>

using namespace std;

class Date {
private:
	int d, m, y;

public:
	Date() {
		//cout << "Constructor Date" << endl;
		d = rand() % 30 + 1;
		m = rand() % 12 + 1;
		y = rand() % 50 + 1970;
	}

	~Date() {}

	int getDay() { return d; }
	int getMonth() { return m; }
	int getYear() { return y; }

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