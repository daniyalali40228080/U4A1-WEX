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
	bool applied = false;
};

vector<Opportunity> opportunitiesList;
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
	char apply;
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
		cout << "Applied: " << endl;
	}
	welcome(); // Return to main menu
}
void searchOpportunity() {
	cout << "Searching through all opportunities that you have applied to...";
	cout << endl;
	// Search through for all applied opportunities
	for (int i = 0; i < opportunitiesList.size(); i++) {
		if (opportunitiesList[i].applied) {
			cout << "Name: " << opportunitiesList[i].name << endl;
			cout << "Company: " << opportunitiesList[i].company << endl;
			cout << "Description: " << opportunitiesList[i].description << endl;
			cout << "Date: " << opportunitiesList[i].date << endl;
			cout << "Qualifications Required: " << opportunitiesList[i].qualifications << endl;
			cout << "Location: " << opportunitiesList[i].location << endl;
			cout << "Number of Hours: " << opportunitiesList[i].hours << endl;
			cout << "Number of Positions Available: " << opportunitiesList[i].positionsAvailable << endl;
			cout << "Applied: " << opportunitiesList[i].applied << endl;
		}
	}
	welcome(); // Return to main menu
}

void applyOpportunity() {
	cout << endl << "Listing all opportunities you have not applied to..." << endl;
	for (int i = 0; i < opportunitiesList.size(); i++) {
		if (not opportunitiesList[i].applied) {
			cout << "Name: " << opportunitiesList[i].name << endl;
			cout << "Company: " << opportunitiesList[i].company << endl;
			cout << "Description: " << opportunitiesList[i].description << endl;

			if (not opportunitiesList[i].applied) {
				char applyOption;
				cout << endl << "Would you like to apply to this experience? (Y/N) Option: ";
				cin >> applyOption;
				if (applyOption == 'Y') {
					opportunitiesList[i].applied = true;
				}
				else {
					cout << "You have not applied to this experience." << endl;
				}
			}
		}
	}
}