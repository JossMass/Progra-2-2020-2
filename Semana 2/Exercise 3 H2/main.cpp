#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Account {
private:
	//Attributes
	string holder;
	double quantity;

public:
	//Methods
	//Constructors and Destructors
	Account(string holder) {
		this->holder = holder;
		quantity = 0;
	}

	Account(string holder, double quantity) {
		this->holder = holder;
		this->quantity = quantity;
	}

	~Account() {}

	void addMoneyToAccount(double q) {
		if (q >= 0) {
			quantity += q;
		}
	}

	void removeMoneyToAccount(double q) {
		quantity -= q;
		if (quantity < 0) {
			quantity = 0;
		}
	}

	//Set and Get
	string getHolder() { return holder; }
	void setHolder(string v) { holder = v; }
	double getQuantity() { return quantity; }
	void setQuantity(double v) { quantity = v; }
};

int main() {
	Account* a; // Declaracion
	a = new Account("Lucia"); //Instancia

	cout << a->getHolder() << endl;
	a->addMoneyToAccount(360);
	cout << a->getQuantity() << endl;
	a->removeMoneyToAccount(120);
	cout << a->getQuantity();


	_getch();
	return 0;
}