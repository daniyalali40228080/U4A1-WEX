#include <iostream>
using namespace std;

//Initialise external functions
void experiencesMenu();

void studentLogin() {
	string studentUsername, studentPassword;
	cout << endl << "Enter student username: ";
	cin >> studentUsername;
	cout << "Enter student password: ";
	cin >> studentPassword;

	if (studentUsername == "student" && studentPassword == "student") {
		experiencesMenu();
	}
};