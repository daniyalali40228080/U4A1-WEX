#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <fstream> // For file handling
using namespace std;

const string opportunitiesFile = "opportunities.txt";

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

void saveVector() {
	ofstream output_file(opportunitiesFile, ios::app); // Append mode
	if (output_file.is_open()) {
		for (const auto& opp : opportunitiesList) {
			output_file << opp.name << '\n' << opp.company << '\n' << opp.description << '\n'
				<< opp.date << '\n' << opp.qualifications << '\n' << opp.location << '\n'
				<< opp.hours << '\n' << opp.positionsAvailable << '\n' << opp.applied << '\n';
		}
	}
	else {
		cerr << "Error opening file for writing.\n";
	}
	output_file.close();
}

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

	saveVector();
	welcome(); // Return to main menu
}

void loadOpportunities() {
	ifstream input_file(opportunitiesFile);
	Opportunity opp;
	while (input_file >> opp.name >> opp.company >> opp.description >> opp.date
		>> opp.qualifications >> opp.location >> opp.hours >> opp.positionsAvailable >> opp.applied) {
		opportunitiesList.push_back(opp);
	}
	input_file.close();
}


void displayOpportunities() {
	cout << endl << endl;
	loadOpportunities();
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
	string searchCriteria;
	cout << "This feature searches through all the opportunities you have applied to, to continue enter the name of the opportunity.";
	cout << endl;
	cin >> searchCriteria;
	// Search through for all applied opportunities
	for (int i = 0; i < opportunitiesList.size(); i++) {
		if (opportunitiesList[i].applied && searchCriteria == opportunitiesList[i].name) {
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
					cout << endl << "Applied to opportunitity successfully!" << endl;
					saveVector();
					welcome();
				}
				else {
					cout << "You have not applied to this experience." << endl;
					welcome();
				}
			}
		}
	}
}