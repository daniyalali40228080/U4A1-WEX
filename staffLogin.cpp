#include <iostream>
using namespace std;

//Initialise external functions
void employerMenu();
void displayOpportunities();

void staffLogin() {
	string staffUsername, staffPassword; // Initalise Variables
	cout << endl << "Enter staff username: ";
	cin >> staffUsername; // Wait for input
	cout << "Enter staff password: ";
	cin >> staffPassword; // Wait for input

	// Verify credentials are correct
	if (staffUsername == "staff" && staffPassword == "staff") {
		cout << endl << "Logged In Successfully!" << endl;
		cout << endl << "Please select one of the following options:\n 1) Display All Opportunities\n 2) Employer Menu" << endl << endl;
		int option;
		cin >> option; // Wait for input

		switch (option) {
		case 1:
			displayOpportunities();
			break;
		case 2:
			employerMenu();
			break;
		default:
			staffLogin();
			break;
		}
	}
	else {
		cout << "Credentials are incorrect! Try again." << endl;
		staffLogin();
	}
};

void addOpportunity();
void displayOpportunities();
void searchOpportunity();
void employerMenu();

void employerMenu() {
	string employerUser, employerPass; // Initalise Variables
	cout << endl << "Enter employer username: ";
	cin >> employerUser; // Wait for input
	cout << "Enter employer password: ";
	cin >> employerPass; // Wait for input

	if (employerUser == "employer" && employerPass == "employer") {
		// Ask to select an option
		cout << "Select one of the following options:\n 1) Add an Opportunity\n 2) Display all Opportunities\n 3) Search for an Opportunity\n\nOption: ";
		int option;
		cin >> option;

		// Cycle through each option until correct one found and redirect
		switch (option) {
		case 1:
			addOpportunity();
			break;
		case 2:
			displayOpportunities();
			break;
		case 3:
			searchOpportunity();
			break;
		default:
			// On wrong option return to previous menu
			cout << "Invalid Option! Returning to Menu...";
			employerMenu();
			break;
		}
	}
	else {
		cout << "Incorrect Password! Try again.";
		employerMenu();
	}
}
