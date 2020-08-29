#include <iostream>
#include <conio.h>
#include <ctime>
#include "Person.h"

using namespace std;

int main() {
	srand(time(NULL));

	string name;
	char gender;
	int age;
	double height;
	double weight;

	cout << "Name: "; cin >> name;
	cout << "Gender: "; cin >> gender;
	cout << "Age: "; cin >> age;
	/*cout << "Height: "; cin >> height;
	cout << "Weight: ";  cin >> weight*/;
	cout << endl;

	/*Person* obj1 = new Person(name, age, gender, height, weight);
	obj1->getInformation();*/
	Person* obj2 = new Person(name, age, gender);
	obj2->setHeight(2);
	obj2->setWeight(120);
	obj2->checkGender();
	obj2->getInformation();
	cout << "The person is legal: " << obj2->isLegalAge() << endl;
	cout << "The person IMC is: " << obj2->calculateIMC() << endl;


	_getch();
	return 0;
}