#include <iostream>
using namespace std;

//Initialise external functions
void experiencesMenu();
void employerMenu();

void staffLogin() {
	string staffUsername, staffPassword;
	cout << endl << "Enter staff username: ";
	cin >> staffUsername;
	cout << "Enter staff password: ";
	cin >> staffPassword;

	if (staffUsername == "staff" && staffPassword == "staff") {
		cout << endl << "Please select one of the following options:\n 1) Experiences Menu\n 2) Employer Menu" << endl << endl;
		int option;
		cin >> option;

		switch (option) {
		case 1:
			experiencesMenu();
			break;
		case 2:
			employerMenu();
			break;
		}
	}
	else {
		cout << endl << "Incorrect password! Please try again.";
	}
};