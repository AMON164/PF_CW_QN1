

#include <iostream>
using namespace std;


int main() {

    string userid_capturedRegistration;
    string userid_passwordRegistered;
    double balance = 0.0;
    bool loginStatusOfUser = false;
    char user_option;

    string userId, password;

    while (true) {
        if (!loginStatusOfUser) {
            // User is not logged in, show the main menu
            cout << "Welcome to the ATM Machine!" << endl;
            cout << "Choose an option:" << endl;
            cout << "l - Login" << endl;
            cout << "c - Create New Account" << endl;
            cout << "q - Quit" << endl;
            cout << "> ";
            cin >> user_option;

            if (user_option == 'c') {
                // Allow the user to create a new account
                cout << "Enter a new user id: ";
                cin >> userid_capturedRegistration;
                cout << "Enter a new password: ";
                cin >> userid_passwordRegistered;
                cout << "Account created successfully!" << endl;

            } else if (user_option == 'l') {
                // Allow the user to login
                cout << "Enter your user id: ";
                cin >> userId;
                cout << "Enter your password: ";
                cin >> password;

                if (userId == userid_capturedRegistration && password == userid_passwordRegistered) {
                    cout << "***LOGIN SUCCESSFUL!***" << endl;
                    loginStatusOfUser = true; // Set logged in to true
                } else {
                    cout << "***LOGIN FAILED!***" << endl;
                }

            } else if (user_option == 'q') {
                // Quit the program
                cout << "It's a pleasure to have you as our customer" << endl;
                return 0; // Exit the program

            } else {
                cout << "Invalid option. Please try again." << endl;
            }

        } else {
            // User is logged in, show the options menu
            cout << "Choose an option:" << endl;
            cout << "d - Deposit Money" << endl;
            cout << "w - Withdraw Money" << endl;
            cout << "r - Check Balance" << endl;
            cout << "q - Quit" << endl;
            cout << "> ";
            cin >> user_option;

            if (user_option == 'd') {
                // Deposit money
                double deposit;
                cout << "Enter amount to deposit: $";
                cin >> deposit;
                balance += deposit;
                cout << "Deposit successful. Your new balance is $" << balance << "." << endl;

            } else if (user_option == 'w') {
                // Withdraw money
                double withdrawal;
                cout << "Enter amount to withdraw: $";
                cin >> withdrawal;

                if (withdrawal > balance) {
                    cout << "Insufficient funds." << endl;
                } else {
                    balance -= withdrawal;
                    cout << "Withdrawal successful. Your new balance is $" << balance << "." << endl;
                }

            } else if (user_option == 'r') {
                // Check balance
                cout << "Your current balance is $" << balance << "." << endl;

            } else if (user_option == 'q') {
                // Logout
                loginStatusOfUser = false;
                cout << "You have been logged out." << endl;

            } else {
                cout << "Option is not okay. Please try again" << endl;
            }
        }
    }

    return 0;}
