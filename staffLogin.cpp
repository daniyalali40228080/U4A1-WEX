#include <iostream>
#include <conio.h> // Hide Password Module
using namespace std;

//Initialise external functions
void addOpportunity();
void displayOpportunities();
void searchOpportunity();
void welcome();

void staffLogin() {
	string staffUsername, staffPassword; // Initalise Variables
	cout << endl << "Enter staff username: ";
	cin >> staffUsername; // Wait for input
	cout << "Enter staff password: ";

	char key;
	while ((key = _getch()) != '\r') {  // Enter key ('\r') to submit
		if (key == '\b') {  // Handle backspace
			if (!staffPassword.empty()) {
				staffPassword.pop_back();
				cout << "\b \b";  // Remove '*' from screen
			}
		}
		else {
			staffPassword += key;
			cout << '*';  // Show '*' instead of actual character
		}
	}

	
	if (staffUsername == "staff" && staffPassword == "staff") {
		// Ask to select an option
		cout << endl << "Select one of the following options:\n 1) Add an Opportunity\n 2) Display all Opportunities\n 3) Search for an Opportunity\n\nOption: ";
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
			
		cout << "Incorrect Credentials! Try again.";
		staffLogin();
	}
}
