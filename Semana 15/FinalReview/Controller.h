#pragma once
#include "Enemy.h"
#include "Hero.h"
#include <vector>

using namespace std;

class Controller {
private:
	Hero* hero;
	vector<Enemy*> enemies;
	int time;

public:
	Controller(int x, int y, Bitmap^ bmpHero, int HP, Bitmap^ bmpEnemy) {
		time = 0;
		hero = new Hero(x, y, bmpHero->Width / 4, bmpHero->Height / 4, HP);
		for (int i = 0; i < 5; i++) {
			enemies.push_back(new Enemy(rand() % 600, rand() % 300, bmpEnemy->Width / 4, bmpEnemy->Height / 4));
		}
	}

	~Controller(){}

	void moveEveything(Graphics^ g) {
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->move(g);
		}
	}

	void drawEverything(Graphics^ g, Bitmap^ bmpHero, Bitmap^ bmpEnemy, Bitmap^ bmpMap) {
		g->DrawImage(bmpMap, 0, 0, bmpMap->Width * 2.2, bmpMap->Height * 1.6);
		hero->draw(g, bmpHero);
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->draw(g, bmpEnemy);
		}
	}

	void collision() {
		for (int i = 0; i < enemies.size(); i++) {
			if (hero->getRectangle().IntersectsWith(enemies[i]->getRectangle())) {
				hero->decreaseHP();
				hero->setX(25);
				hero->setY(25);
				enemies[i]->setVisible(false);
			}
		}

		for (int i = 0; i < enemies.size(); i++) {
			if (!enemies[i]->getVisible()) {
				enemies.erase(enemies.begin() + i);
			}
		}
	}

	Hero* getHero() { return hero; }
	int getTime() { return time; }
	void increaseTime() { time++; }
};