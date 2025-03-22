#include <iostream>
using namespace std;

//Initialise external functions
void experiencesMenu();
void employerMenu();

void staffLogin() {
	string staffUsername, staffPassword; // Initalise Variables
	cout << endl << "Enter staff username: ";
	cin >> staffUsername; // Wait for input
	cout << "Enter staff password: ";
	cin >> staffPassword; // Wait for input

	// Verify credentials are correct
	if (staffUsername == "staff" && staffPassword == "staff") {
		cout << endl << "Logged In Successfully!" << endl;
		cout << endl << "Please select one of the following options:\n 1) Experiences Menu\n 2) Employer Menu" << endl << endl;
		int option;
		cin >> option; // Wait for input

		switch (option) {
		case 1:
			experiencesMenu();
			break;
		case 2:
			employerMenu();
			break;
		}
		default:
			staffLogin();
			break;
	}
};