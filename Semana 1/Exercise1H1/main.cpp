#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;
//Camel case
void generateValues(int* myArray, int n) {
	for (int i = 0; i < n; i++) {
		myArray[i] = rand() % 100;
	}
}

void printValues(int* myArray, int n) {
	for (int i = 0; i < n; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl;
}

void findMajorNumber(int* myArray, int n) {
	int major = 0;
	int position = 0;

	for (int i = 0; i < n; i++) {
		if (myArray[i] > major) {
			major = myArray[i];
			position = i;
		}
	}

	cout << "The major number in the array is: " << major
		<< " an its position is: " << position << endl;
}


void findMinorNumber(int* myArray, int n) {
	int minor = 100;
	int position = 0;

	for (int i = 0; i < n; i++) {
		if (myArray[i] < minor) {
			minor = myArray[i];
			position = i;
		}
	}

	cout << "The minor number in the array is: " << minor
		<< " an its position is: " << position << endl;
}

void bubbleSort(int* myArray, int n) {
	int aux;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (myArray[j] < myArray[j + 1]) {
				aux = myArray[j];
				myArray[j] = myArray[j + 1];
				myArray[j + 1] = aux;
			}
		}
	}
}

void showAverageNumber(int* myArray, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += myArray[i];
	}

	cout << "The average number is: " << double(sum) / n << endl;
}

void percentageMajorMinorFifty(int* myArray, int n) {
	int majorCounter = 0;
	int minorCounter = 0;

	int majorPercentage, minorPercentage;

	for (int i = 0; i < n; i++) {
		if (myArray[i] <= 50) {
			minorCounter++;
		}
		else {
			majorCounter++;
		}
	}

	majorPercentage = double(majorCounter) * 100 / n;
	minorPercentage = double(minorCounter) * 100 / n;

	cout << "The percentage of numbers major fifty is: " << majorPercentage << "%" << endl;
	cout << "The percentage of numbers minor fifty is: " << minorPercentage << "%" << endl;

}

void menu() {
	cout << "1. Print Values" << endl;
	cout << "2. Find major number and position" << endl;
	cout << "3. Find minor number and position" << endl;
	cout << "4. Execute bubble sort" << endl;
	cout << "5. Average number" << endl;
	cout << "6. Show Percentage" << endl;

}

int main() {
	srand(time(NULL));
	int option;
	int n = 10;
	int* myArray = new int[n];

	generateValues(myArray, n);

	while (1) {
		menu();
		cout << "Enter the option: "; cin >> option;

		switch (option) {
		case 1: printValues(myArray, n); break;
		case 2: findMajorNumber(myArray, n); break;
		case 3: findMinorNumber(myArray, n); break;
		case 4: bubbleSort(myArray, n); break;
		case 5: showAverageNumber(myArray, n); break;
		case 6: percentageMajorMinorFifty(myArray, n);
		}

		_getch();
		system("cls");
	}


	_getch();
	return 0;
}