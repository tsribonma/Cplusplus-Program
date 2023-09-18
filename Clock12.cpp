// Tricia Ann Sribonma
// September 17, 2023
// CS-210-X6063
// Project One: Chada Tech 12 & 24-hour clocks

#include "Clock12.h"  // Calling on the parent class AKA header file
#include <chrono> // C++ standard library for current time I/O
#include <iostream> // Supporting I/O string input

using namespace std;

// Declaring constructor and object default time when initialized in program
Clock12::Clock12() {
    // Real time retrieval for any timezone user
    time_t rawTime;
    struct tm* timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

        // Initializing hour, minute, and second using real time retrieval
    hour = timeInfo->tm_hour;
    minute = timeInfo->tm_min;
    second = timeInfo->tm_sec;
    isAM = true;  // Setting true statement for AM hours (false for PM hours)
}

// Add one hour up until the 12th hour to define
// difference between 12 AM or 12 PM for example.
// if condition ensures once 11 AM has ended
// 12 PM with sequential PM hours will repeat until 11 PM.
// Where process will repeat.
void Clock12::addHour() {
    hour = (hour % 12) + 1;
    if (hour == 12) {
        isAM = !isAM;
    }
}

// Add one minute up until the 60th minute
//which converts to add one hour if minutes
//are added beyond 60 minutes
void Clock12::addMinute() {
    minute = (minute + 1) % 60;
    if (minute == 0) {
        addHour();
    }
}

// Add one minute up until the 60th second
//which converts to add one minute if seconds
//are added beyond 60 minutes
void Clock12::addSecond() {
    second = (second + 1) % 60;
    if (second == 0) {
        addMinute();
    }
}

// Printing output in 12-hour format using HH:MM:SS structure
// with appropriate AM or PM notations following time formats
std::string Clock12::getTime() {
    std::string ampm = isAM ? "AM" : "PM";
    std::string formattedHour = (hour < 10) ? "0" + std::to_string(hour) : std::to_string(hour);
    std::string formattedMinute = (minute < 10) ? "0" + std::to_string(minute) : std::to_string(minute);
    std::string formattedSecond = (second < 10) ? "0" + std::to_string(second) : std::to_string(second) + " " + ampm;

    return formattedHour + ":" + formattedMinute + ":" + formattedSecond;
}