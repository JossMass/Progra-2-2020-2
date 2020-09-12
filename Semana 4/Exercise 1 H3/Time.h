#pragma once
#include <string>

using namespace std;

class Time {
private:
	int h, m, s;

public:
	Time() {
		h = rand() % 24;
		m = rand() % 60;
		s = rand() % 60;
	}

	~Time() {}

	int getHour() { return h; }

	string getCompleteTime() {
		//hh:mm:ss
		string aux;
		aux.append(to_string(h));
		aux.append(":");
		aux.append(to_string(m));
		aux.append(":");
		aux.append(to_string(s));

		return aux;
	}
};