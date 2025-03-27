#include <iostream>
#include <conio.h> // Hide Password Module
using namespace std;

//Initialise external functions
void addOpportunity();
void displayOpportunities();
void searchOpportunity();
void welcome();

int loginAttempts = 3; // Adjusted to 3 for clarity

void staffLogin() {
    string staffUsername, staffPassword; // Initialise Variables

    while (loginAttempts > 0) {
        cout << endl << "Enter staff username: ";
        cin >> staffUsername;
        cout << "Enter staff password: ";
        cin >> staffPassword;

        if (staffUsername == "employer" && staffPassword == "employer") {
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
            return; // Exit after successful login and option handling
        } else {
            loginAttempts--;
            if (loginAttempts > 0) {
                cout << "Incorrect username or password! Try again.\n";
                cout << "You have " << loginAttempts << " login attempts remaining.\n";
            } else {
                cout << "Too many failed attempts. Exiting program.\n";
                return; // Exit after exceeding login attempts
            }
        }
    }
}
