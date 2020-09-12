#include <iostream>
#include <ctime>
#include <conio.h>
#include "ArrEclipse.h"

using namespace std;

void Menu() {
    cout << "1. Add Eclipse" << endl;
    cout << "2. Insert Eclipse" << endl;
    cout << "3. Edit Eclipse Type" << endl;
    cout << "4. Delete Eclipse" << endl;
    cout << "5. Print all Eclipses" << endl;
    cout << "6. Report Eclipses in Europe" << endl;
    cout << "7. Report Eclipses Earthquakes" << endl;
    cout << "8. Report Eclipses in the night" << endl << endl;
}

int main() {
    srand(time(NULL));
    int option, position;
    string type;
    ArrEclipse* arr = new ArrEclipse();

    while (1) {
        Menu();
        cout << "Input the option: "; cin >> option;
        switch (option) {
        case 1: arr->addEclipse(); cout << "Eclipse added" << endl; break;
        case 2:
            cout << "Input the position: "; cin >> position;
            arr->insertEclipse(position); cout << "Eclipse inserted" << endl; break;
        case 3:
            cout << "Input the position: "; cin >> position;
            cout << "Input the new value: "; cin >> type;
            arr->editEclipseType(position, type);
            cout << "Eclipse edited" << endl; break;
        case 4:
            cout << "Input the position: "; cin >> position;
            arr->deleteEclipse(position); cout << "Eclipse deleted" << endl; break;
        case 5:  arr->printArray(); break;
        case 6:  arr->eclipsesVisiblesEurope(); break;
        case 7: arr->eclipsesEarthquakes(); break;
        case 8: arr->eclipsesInTheNight(); break;
        }
        _getch();
        system("cls");
    }

    _getch();
    return 0;
}