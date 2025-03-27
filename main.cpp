#include <iostream>
using namespace std;

// Initalise Functions
void staffLogin();
void studentLogin();

void welcome() {
	// Print welcome message
	cout << endl << "--------------- " << "Welcome to HRUC Work Experience Management System." << " ---------------" << endl;

	cout << endl << "Please select one of the following options:\n\n 1) Student Login\n 2) Staff Login\n 3) Exit the program" << endl << endl << "Option: ";
	int option;
	cin >> option;

	// Switch to redirect to selected option
	switch (option) {
	case 1:
		cout << endl << "--- Student Login | HRUC WEX System ---" << endl;
		studentLogin();
		break;
	case 2:
		cout << endl << "--- Staff Login | HRUC WEX System ---" << endl;
		staffLogin();
		break;
    case 3:
        cout << endl << endl << "--- Terminated Program ---";
	default:
		cout << endl << "Invalid option! Try again.";
		welcome();
		break;
	}
}

int main() {
	welcome(); // Start with welcome screen
	return 0;
}
