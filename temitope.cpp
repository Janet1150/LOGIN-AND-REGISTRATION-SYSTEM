// These are the header files that we need for the code.
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>

// The line below "using namespace std" statement makes
//it unnecessary to prefix the standard library functions with "std::"

using namespace std;
// If the user selects registration, prompt them for a firstname, lastname, username, password. Store the username and password in a file or database.

void registerUser() {

    string firstname, lastname, username, password;
    cout << "Enter your firstname: ";
    cin >> firstname;
    cout << "Enter your lastname:"; 
    cin >> lastname;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter Your password";
    cin >> password;
    // cout << ""; 1 ""
    ofstream outfile;
    outfile.open("users.txt", ios::app);
    outfile << firstname<< " " << lastname << " " << username << " " << password << endl;
    outfile.close();
    cout << "Registration successful!" << endl;

}

// If the user selects login, prompt them for their username and password. Check if the username and password match those stored in the file or database. If they do, allow the user to proceed. If not, prompt the user to try again or offer to reset their password.


bool loginUser() {
    string username, password, stored_password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    ifstream infile;
    infile.open("users.txt");
    while (infile >> username >> stored_password) {
        if (password == stored_password) {
            infile.close();
            cout << "Login successful!" << endl;
            return true;
        }
    }
    infile.close();
    cout << "Invalid username or password. Please try again." << endl;
    return false;
}

void intro();
int main() {
    intro();
    int choice;
    cout << " \n\n\n\t 1. REGISTER \n\n\n\t 2. LOGIN\n";
    cin >> choice;
    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            while (!loginUser()) {
         // keep prompting for login until successful
            }
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
    return 0;
}
        // Introduction section 
void intro(){
    cout << "\n\n\n\t     TOPIC: LOGIN AND REGISTRATION SYSTEM";
    cout << "\n\n\n\n\t     MADE BY: WILSON JANET TEMITOPE";
    cout << "\n\n\n\n\t     MATRIC NO: H/CTE/22/0708 ";
    cout << "\n\n\n\n\t     SUPERVISOR : ENGR NZUBE";
    cout << "\n\n\n\n\t     SCHOOL : THE FEDERAL POLYTECHNIC ILARO";
    cin.get();
}