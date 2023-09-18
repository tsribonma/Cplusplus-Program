// Tricia Ann Sribonma
// September 17, 2023
// CS-210-X6063
// Project One: Chada Tech 12 & 24-hour clocks

#pragma once
#ifndef CLOCK24_H // Guarding header from duplicates that cause errors
#define CLOCK24_H // Defines macro file name for extraction among other source or header files

#include <string>

class Clock24 { // Establishing public class named Clock24 header file for cpp
public:
    Clock24();  // Constructor initializing clock to 00:00:00
    void addHour();     // One hour added to 24-hour clock
    void addMinute();   // One minute added to 24-hour clock
    void addSecond();   // One second added to 24-hour clock
    std::string getTime();  // Retrieves current time in (HH:MM:SS AM/PM)

private: // Establish private class for 12-hour clock conversion
    int hour; // Refers to 1 to 12-hours
    int minute; // Refers to 0 to 59 minutes
    int second; // Refers to 0 to 59 seconds
    // Boolean AM PM is not needed in 24-hour clock
};

#endif // CLOCK24_H // Ending header file