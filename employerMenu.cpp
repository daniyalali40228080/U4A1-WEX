#include <iostream>
using namespace std;

void employerMenu() {
	cout << "Logged In Successfully!";

	cout << endl << "--------------" << endl << "Select an option from the following:\n 1) Add New Experience\n 2) Edit Current Experience\n 3) Delete Current Experience" << endl;
	int option;
	cin >> option;

	switch (option) {
	case 1:
		cout << endl << "-------------- Add Experience --------------";
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}