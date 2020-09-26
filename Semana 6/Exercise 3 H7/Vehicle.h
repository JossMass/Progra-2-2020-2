#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Vehicle {
protected:
	int x, y;
	int model;
	int place;
	bool arrive;
	int victories;
	int width;

public:
	Vehicle(int x, int y) {
		this->x = x;
		this->y = y;
		width = 0;
		victories = 0;
		place = 0;
		arrive = false;
		model = rand() % 2;
	}



	~Vehicle(){}

	void increaseVictories() { victories++; }

	int getX() { return x; }
	int getY() { return y; }
	int getPlace() { return place; }
	bool getArrive() { return arrive; }
	int getVictories() { return victories; }

	void setX(int v) { x = v; }
	void setY(int v) { y = v; }
	void setPlace(int v) { place = v; }
	void setArrive(int v) { arrive = v; }
	void setVictories(int v) { victories = v; }

	void move() {
		if (x + width <= 70) x += rand() % 3 + 1;
		else arrive = true;
	}
};