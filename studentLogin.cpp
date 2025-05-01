#include <iostream>
using namespace std;

//Initialise external functions
void displayOpportunities();
void searchOpportunity();

int loginAttempts = 2;

void studentLogin() {
	string studentUsername, studentPassword; // Initalise Variables
	cout << endl << "Enter student username: ";
	cin >> studentUsername;
	cout << "Enter student password: ";
	cin >> studentPassword;
	if (!loginAttempts == 0) {
		// Check if credentials are correct
		if (studentUsername == "student" && studentPassword == "student") {
			cout << "Logged In Successfully!" << endl;

			cout << "Select one of the following options:\n 1) Display all opportunities\n 2) Search for opportunity\n\nOption: ";
			int option;
			cin >> option;

			// Switch to redirect use to the selected option
			switch (option) {
			case 1:
				displayOpportunities();
				break;
			case 2:
				searchOpportunity();
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
	}
	else {
		cout << endl << "Exceed Maximum login attempts. Terminating program...";
	}
};
