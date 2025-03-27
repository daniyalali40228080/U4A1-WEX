#include <iostream>
#include <conio.h> // Hide Password Module
using namespace std;

//Initialise external functions
void displayOpportunities();
void searchOpportunity();
void applyOpportunity();

void studentLogin() {

	string studentUsername, studentPassword; // Initalise Variables
	cout << endl << "Enter student username: ";
	cin >> studentUsername;
	cout << "Enter student password: ";
	
	char key;
	while ((key = _getch()) != '\r') {  // Enter key ('\r') to submit
		if (key == '\b') {  // Handle backspace
			if (!studentPassword.empty()) {
				studentPassword.pop_back();
				cout << "\b \b";  // Remove '*' from screen
			}
		}
		else {
			studentPassword += key;
			cout << '*';  // Show '*' instead of actual character
		}
	}


	// Check if credentials are correct
	if (studentUsername == "student" && studentPassword == "student") {
		cout << endl << "Logged In Successfully!" << endl;

		cout << "Select one of the following options:\n 1) Display all opportunities\n 2) Apply for opportunity\n\nOption: ";
		int option;
		cin >> option;

		// Switch to redirect use to the selected option
		switch (option) {
		case 1:
			displayOpportunities();
			break;
		case 2:
			applyOpportunity();
			break;
		default:
			cout << "Invalid Option! Returning to Menu...";
			studentLogin();
			break;
		}
	}
	else {
		cout << "Incorrect Password! Try again.";
		studentLogin();
	}
};
