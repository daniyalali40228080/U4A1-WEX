#include <iostream>
#include <vector>
using namespace std;

struct Opportunity {
	string name;
	string company;
	string description;
	string date;
	string qualifications;
	string location;
	int hours;
	int positionsAvailable;
};

vector<Opportunity> opportunitiesList;
void experiencesMenu();
void welcome();

void addOpportunity() {
	Opportunity x;

	cout << "Enter the name of the opportunity: " << endl;
	cin >> x.name;
	cout << "Enter the company hosting the opportunity: " << endl;
	cin >> x.company;
	cout << "Enter the descripition of the opportunity: " << endl;
	cin >> x.description;
	cout << "Enter the date of when the opportunity is taking place: " << endl;
	cin >> x.date;
	cout << "Enter the qualifications required for the opportunity: " << endl;
	cin >> x.qualifications;
	cout << "Enter the location of the opportunity: " << endl;
	cin >> x.location;
	cout << "Enter the number of hours to be worked during the opportunity: " << endl;
	cin >> x.hours;
	cout << "Enter the number of positions available: " << endl;
	cin >> x.positionsAvailable;
	opportunitiesList.push_back(x);
	welcome(); // Return to main menu
}

void displayOpportunities() {
	cout << endl << endl;
	for (int i = 0; i < opportunitiesList.size(); i++) {
		cout << "Name: " << opportunitiesList[i].name << endl;
		cout << "Company: " << opportunitiesList[i].company << endl;
		cout << "Description: " << opportunitiesList[i].description << endl;
		cout << "Date: " << opportunitiesList[i].date << endl;
		cout << "Qualifications Required: " << opportunitiesList[i].qualifications << endl;
		cout << "Location: " << opportunitiesList[i].location << endl;
		cout << "Number of Hours: " << opportunitiesList[i].hours << endl;
		cout << "Number of Positions Available: " << opportunitiesList[i].positionsAvailable << endl;
	}
	welcome(); // Return to main menu
}

void searchOpportunity() {
	string searchCriteria;
	cout << "Enter the name of the opportunity you want to search for: " << endl << "Option: ";
	cin >> searchCriteria;
	// Enter name of opportunity
	cout << endl;
	// Search through all names until search name matches and return details
	for (int i = 0; i < opportunitiesList.size(); i++) {
		if (searchCriteria == opportunitiesList[i].name) {
			cout << "Name: " << opportunitiesList[i].name << endl;
			cout << "Company: " << opportunitiesList[i].company << endl;
			cout << "Description: " << opportunitiesList[i].description << endl;
			cout << "Date: " << opportunitiesList[i].date << endl;
			cout << "Qualifications Required: " << opportunitiesList[i].qualifications << endl;
			cout << "Location: " << opportunitiesList[i].location << endl;
			cout << "Number of Hours: " << opportunitiesList[i].hours << endl;
			cout << "Number of Positions Available: " << opportunitiesList[i].positionsAvailable << endl;
		}
	}
	welcome(); // Return to main menu
}

void experiencesMenu() {
	// Display welcome message
	cout << endl << "--------------- Experiences Menu | HRUC WEX System ---------------" << endl;
	cout << endl << "Select one of the following options to be redirected to the correct page:\n\n 1) Add Opportunity\n 2) Display All Opportunities\n 3) Search for an Opportunity\n 4) Return to Main Menu" << endl << "Option: ";
	int option;
	cin >> option; // Wait for input

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
	case 4:
		welcome();
		break;
	default:
		cout << "Invalid Option!";
		welcome(); // Return to main menu
	}
}