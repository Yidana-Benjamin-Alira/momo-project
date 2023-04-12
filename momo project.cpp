#include <iostream>
#include <string>
using namespace std;

// Global Variables
int balance = 1000;
int attempts = 0;
int pin = 0000;

// Function Prototypes
void authenticate();
void reset_pin();
void check_balance();
void send_money();
void exit_program();

int main()
{
    // Display Welcome message and prompt for action
    cout << "Welcome to MegaMind Benjee Mobile Money Service." << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Authenticate" << endl;
    cout << "2. Reset Pin" << endl;
    cout << "3. Check Balance" << endl;
    cout << "4. Send Money" << endl;
    cout << "5. Exit" << endl;

    // Get user input and call appropriate function
    int choice;
    cin >> choice;

    switch (choice)
    {
        case 1:
            authenticate();
            break;
        case 2:
            reset_pin();
            break;
        case 3:
            check_balance();
            break;
        case 4:
            send_money();
            break;
        case 5:
            exit_program();
            break;
        default:
            cout << "Invalid choice. Please select again." << endl;
            main();
    }

    return 0;
}

// Function Definitions

void authenticate()
{
    int entered_pin;
    cout << "Please enter your PIN:" << endl;
    cin >> entered_pin;

    if (entered_pin == pin)
    {
        cout << "Authentication successful." << endl;
        attempts = 0;
        main();
    }
    else
    {
        attempts++;
        if (attempts < 3)
        {
            cout << "Invalid PIN. Please try again." << endl;
            authenticate();
        }
        else
        {
            cout << "Too many failed attempts. Program will now exit." << endl;
            exit_program();
        }
    }
}

void reset_pin()
{
    int new_pin;
    cout << "Please enter your new PIN:" << endl;
    cin >> new_pin;

    pin = new_pin;
    cout << "PIN successfully changed." << endl;
    main();
}

void check_balance()
{
    cout << "Your balance is: " << balance << endl;
    main();
}

void send_money()
{
    int amount;
    cout << "Please enter the amount to send:" << endl;
    cin >> amount;

    if (amount <= balance)
    {
        balance -= amount;
        cout << "Transaction successful. New balance is: " << balance << endl;
        main();
    }
    else
    {
        cout << "Insufficient funds. Please try again." << endl;
        send_money();
    }
}

void exit_program()
{
    cout << "Thank you for using Mobile Money Service. Goodbye!" << endl;
}
	
	
	
	
