#include <iostream>
#include <conio.h> // Hide Password Module
using namespace std;

//Initialise external functions
void addOpportunity();
void displayOpportunities();
void searchOpportunity();
void welcome();

void staffLogin() {
    string staffUsername, staffPassword; // Initialise Variables

    int loginAttempts = 2; // Number of password attempts allowed

    while (loginAttempts > 0) {
        cout << endl << "Enter staff username: ";
        cin >> staffUsername;
        cout << "Enter staff password: ";

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

        if (staffUsername == "staff" && staffPassword == "staff") {
            // Ask to select an option
            cout << "Select one of the following options:\n"
                 << " 1) Add an Opportunity\n"
                 << " 2) Display all Opportunities\n"
                 << " 3) Search for an Opportunity\n\n"
                 << "Option: ";
            int option;
            cin >> option;

            // Handle the selected option
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
                    cout << "Invalid Option! Returning to Menu...\n";
                    welcome();
                    break;
            }
        } 
        else {
            loginAttempts--;

            cout << "Incorrect username or password! Try again.\n";
            cout << "You have " << loginAttempts << " login attempts remaining.\n";
            staffLogin();
        }
    }
    if (loginAttempts =< 0) {
        cout << endl << endl << "Exceeded maximum amount of login attempts, terminating program...";
        exit(0);
    }
}
