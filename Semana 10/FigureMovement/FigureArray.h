#pragma once
#include "MyRectangle.h"
#include "MyTriangle.h"
#include "MyEllipse.h"
#include <vector>

using namespace std;

class FigureArray {
private:
	vector<MyRectangle*> myRectangles;
	vector<MyTriangle*> myTriangles;
	vector<MyEllipse*> myEllipses;

public:
	FigureArray(){}
	~FigureArray() {}

	void addMyRectangle() {
		myRectangles.push_back(new MyRectangle());
	}

	void addMyTriangle() {
		myTriangles.push_back(new MyTriangle());
	}

	void addMyEllipse() {
		myEllipses.push_back(new MyEllipse());
	}

	void drawEverything(Graphics^ g) {
		for (int i = 0; i < myRectangles.size(); i++) {
			myRectangles[i]->draw(g);
		}

		for (int i = 0; i < myEllipses.size(); i++) {
			myEllipses[i]->draw(g);
		}

		for (int i = 0; i < myTriangles.size(); i++) {
			myTriangles[i]->draw(g);
		}
	}

	void moveEverything(Graphics^ g) {
		for (int i = 0; i < myRectangles.size(); i++) {
			myRectangles[i]->move(g);
		}

		for (int i = 0; i < myEllipses.size(); i++) {
			myEllipses[i]->move(g);
		}

		for (int i = 0; i < myTriangles.size(); i++) {
			myTriangles[i]->move(g);
		}
	}
};