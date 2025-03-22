#include <iostream>
using namespace std;

// Initalise Functions
void experiencesMenu();
void staffLogin();
void employerMenu();
void studentLogin();

void welcome() {
	// Print welcome message
	cout << endl << "--------------- " << "Welcome to HRUC Work Experience Management System." << " ---------------" << endl;

	// Prompt to select option
	cout << endl << "Please select one of the following options:\n 1) Student Login\n 2) Staff Login\n 3) Employer Menu" << endl << endl;
	int option;
	cin >> option;

	// Switch to redirect to selected option
	switch (option) {
	case 1:
		cout << endl << "Selected 1" << endl;
		studentLogin();
		break;
	case 2:
		cout << endl << "Selected 2" << endl;
		staffLogin();
		break;
	case 3:
		cout << endl << "Selected 3" << endl;
		employerMenu();
		break;
	default:
		cout << endl << "Invalid option! Try again.";
		break;
	} 
}

int main() {
	welcome(); // Start with welcome screen
	return 0;
}