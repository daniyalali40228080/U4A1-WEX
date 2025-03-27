#include <iostream>
#include <fstream>  // File handling
#include <map>      // Storing credentials
#include <conio.h>  // Hiding password input
using namespace std;

// Function Declarations
void staffLogin();
void studentLogin();
void welcome();

const string PASSWORD_FILE = "credentials.txt";

// Function to load stored passwords
map<string, string> loadCredentials() {
    map<string, string> credentials;
    ifstream file(PASSWORD_FILE);
    string username, password;

    if (file.is_open()) {
        while (file >> username >> password) {
            credentials[username] = password;
        }
        file.close();
    }
    return credentials;
}

// Function to save passwords to file
void saveCredentials(const map<string, string>& credentials) {
    ofstream file(PASSWORD_FILE);
    if (file.is_open()) {
        for (const auto& pair : credentials) {
            file << pair.first << " " << pair.second << endl;
        }
        file.close();
    }
}

// Function to get hidden password input
string getMaskedPassword() {
    string password;
    char ch;
    while ((ch = _getch()) != '\r') {  // Enter key ('\r') to submit
        if (ch == '\b') {  // Handle backspace
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";  // Remove '*' from screen
            }
        }
        else {
            password += ch;
            cout << '*';  // Show '*' instead of actual character
        }
    }
    cout << endl;
    return password;
}

// Function to change password
void changePassword(const string& userType) {
    map<string, string> credentials = loadCredentials();
    string currentPassword, newPassword;

    cout << "\nEnter current password: ";
    currentPassword = getMaskedPassword();

    // Verify current password
    if (credentials[userType] != currentPassword) {
        cout << "Incorrect password! Try again.\n";
        return;
    }

    cout << "Enter new password: ";
    newPassword = getMaskedPassword();

    // Update and save password
    credentials[userType] = newPassword;
    saveCredentials(credentials);

    cout << "Password changed successfully!\n";
}

// Welcome Function
void welcome() {
    // Print welcome message
    cout << endl << "--------------- " << "Welcome to HRUC Work Experience Management System." << " ---------------" << endl;

    cout << endl << "Please select one of the following options:\n\n 1) Student Login\n 2) Staff Login" << endl << endl << "Option: ";
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
    default:
        cout << endl << "Invalid option! Try again.";
        welcome();
        break;
    }
}

// Main Function
int main() {
    welcome(); // Start with welcome screen
    return 0;
}
