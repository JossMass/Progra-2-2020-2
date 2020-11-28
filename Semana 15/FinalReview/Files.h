#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class Files {
private:
	ofstream fileWrite;
	ifstream fileRead;
	int x, y, HP, time;
	string aux;

public:
	Files(){}
	~Files(){}

	void loadData() {
		fileRead.open("configuration.txt", ios::in);

		if (fileRead.fail()) {
			fileRead.close();
			fileWrite.open("configuration.txt", ios::out);

			fileWrite << "25" << endl;
			fileWrite << "25" << endl;
			fileWrite << "3" << endl;
			fileWrite << "20" << endl;

			fileWrite.close();
			fileRead.open("configuration.txt", ios::in);
		}

		getline(fileRead, aux);
		x = atoi(aux.c_str());
		getline(fileRead, aux);
		y = atoi(aux.c_str());
		getline(fileRead, aux);
		HP = atoi(aux.c_str());
		getline(fileRead, aux);
		time = atoi(aux.c_str());

		fileRead.close();
	}

	int getX() { return x; }
	int getY() { return y; }
	int getHP() { return HP; }
	int getTime() { return time; }
};