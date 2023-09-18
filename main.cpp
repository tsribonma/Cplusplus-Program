// Tricia Ann Sribonma
// September 17, 2023
// CS-210-X6063
// Project One: Chada Tech 12 & 24-hour clocks

#include <iostream> // Supporting I/O string input
#include <ctime> // Returns local time for current time I/O
#include "Clock12.h" // Calling on Clock12 parent class from header file
#include "Clock24.h" // Calling on Clock24 parent class from header file
using namespace std;

int main() {
    // Declaring class and objects with variables
    Clock12 clock12;
    Clock24 clock24;
    int choice;

    do { // Setting up variants for switch while loop
        // Menu display to guide user input requirement
        cout << "**************************" << endl;
        cout << "* 1 - Add One Hour       *" << endl;
        cout << "* 2 - Add One Minute     *" << endl;
        cout << "* 3 - Add One Second     *" << endl;
        cout << "* 4 - Exit Program       *" << endl;
        cout << "**************************" << endl;

        // Requiring user input in order to start the format process
        cout << "Enter your choice: ";
        cin >> choice;

        // Filtering user input to adjust clock time accordingly in order
       // to process input into proper 12 and 24 hour formats
        switch (choice) {
        case 1: // Adding one hour increments
            clock12.addHour();
            clock24.addHour();
            break;
        case 2: // Adding one minute increments
            clock12.addMinute();
            clock24.addMinute();
            break;
        case 3: // Adding one second increments
            clock12.addSecond();
            clock24.addSecond();
            break;
        case 4: // Exit program option necessary for any piece of code
            cout << "Exiting program." << endl;
            break;
        default: // Error message if input is not an option
            cout << "Invalid selection. Please try again." << endl;
            break;
        }

        // Showing the 12-hour and 24-hour clock displays with user input
        cout << "**************************        **************************" << endl;
        cout << "*     12-Hour Clock      *        *      24-Hour Clock     *" << endl;
        cout << "*      " << clock12.getTime() << "       *        *        " << clock24.getTime() << "        *" << endl;
        cout << "**************************        **************************" << endl;

    } while (choice != 4);  // Exiting program

    return 0;
}