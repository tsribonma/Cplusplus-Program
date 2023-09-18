// Tricia Ann Sribonma
// September 17, 2023
// CS-210-X6063
// Project One: Chada Tech 12 & 24-hour clocks

#include "Clock24.h" // Calling on the parent class AKA header file
#include <ctime> // Returns local time for current time I/O
#include <iostream> // Supporting I/O string input

using namespace std;

// Declaring constructor and object default time when initialized in program
Clock24::Clock24() {
    // Real time retrieval for any timezone user
    time_t rawTime;
    struct tm* timeInfo;
    
    time(&rawTime);
    timeInfo = localtime(&rawTime);

    // Initializing hour, minute, and second using real time retrieval
    hour = timeInfo->tm_hour;
    minute = timeInfo->tm_min;
    second = timeInfo->tm_sec;
}

// Add one hour up until the 24th hour at most
void Clock24::addHour() {
    hour = (hour + 1) % 24;
}

// Add one minute up until the 60th minute
//which converts to add one hour if minutes
//are added beyond 60 minutes
void Clock24::addMinute() {
    minute = (minute + 1) % 60;
    if (minute == 0) {
        addHour();
    }
}

// Add one minute up until the 60th second
//which converts to add one minute if seconds
//are added beyond 60 minutes
void Clock24::addSecond() {
    second = (second + 1) % 60;
    if (second == 0) {
        addMinute();
    }
}

// Printing output in 24-hour format using HH:MM:SS structure.
// If hour, minute, or second is less than 10 by default it
// adds a 0 to the front to ensure HH:MM:SS format.
string Clock24::getTime() {
    string formattedHour = (hour < 10) ? "0" + to_string(hour) : to_string(hour);
    string formattedMinute = (minute < 10) ? "0" + to_string(minute) : to_string(minute);
    string formattedSecond = (second < 10) ? "0" + to_string(second) : to_string(second);

    return formattedHour + ":" + formattedMinute + ":" + formattedSecond;
}