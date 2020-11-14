#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace System;
using namespace std;

class File {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;
	int n, randX, randY;

public:
	File(){}
	~File() {}

	void readData() {
		fileRead.open("configuration.txt", ios::in);

		if (fileRead.fail()) {
			fileRead.close();

			fileWrite.open("configuration.txt", ios::out);
			fileWrite << "7" << endl;
			fileWrite << "350" << endl;
			fileWrite << "150" << endl;
			fileWrite.close();

			fileRead.open("configuration.txt", ios::in);
		}

		getline(fileRead, text);
		n = atoi(text.c_str());
		getline(fileRead, text);
		randX = atoi(text.c_str());
		getline(fileRead, text);
		randY = atoi(text.c_str());

		fileRead.close();
	}

	int getN() { return n; }
	int getRandX() { return randX; }
	int getRandY() { return randY; }

};