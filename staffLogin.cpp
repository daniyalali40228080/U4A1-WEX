#include <iostream>
using namespace std;

//Initialise external functions
void addOpportunity();
void displayOpportunities();
void searchOpportunity();
void welcome();

int loginAttempts = 2;

void staffLogin() {
	string staffUsername, staffPassword; // Initalise Variables
	cout << endl << "Enter staff username: ";
	cin >> staffUsername; // Wait for input
	cout << "Enter staff password: ";
	cin >> staffPassword; // Wait for input

	if (!loginAttempts == 0) {
		if (staffUsername == "employer" && staffPassword == "employer") {
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
				welcome();
				break;
			}
		}
		else {
			loginAttempts -= 1;
			cout << "Incorrect Password! Try again." << endl << "You have " << loginAttempts << " more login attempts remaining.";
			staffLogin();
		}
	}
	else {
		cout << endl << "Exceed Maximum login attempts. Terminating program...";
	}
}
