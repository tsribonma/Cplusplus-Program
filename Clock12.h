// Tricia Ann Sribonma
// September 17, 2023
// CS-210-X6063
// Project One: Chada Tech 12 & 24-hour clocks

#pragma once
#ifndef CLOCK12_H // Guarding header from duplicates that cause errors
#define CLOCK12_H // Defines macro file name for extraction among other source or header files

#include <string>

class Clock12 { // Establishing public class named Clock12 header file for cpp
public:
    Clock12();  // Constructor initializing clock to 12:00:00 AM
    void addHour();     // One hour added to 12-hour clock
    void addMinute();   // One minute added to 12-hour clock
    void addSecond();   // One second added to 12-hour clock
    std::string getTime();  // Retrieves current time in 12-hour format (HH:MM:SS AM/PM)

private: // Establish private class for 12-hour clock conversion
    int hour; // Refers to 1 to 12-hours
    int minute; // Refers to 0 to 59 minutes
    int second; // Refers to 0 to 59 seconds
    bool isAM; // Setting true statement for AM hours (false for PM hours)
};

#endif // CLOCK12_H // Ending header file