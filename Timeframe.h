#pragma once
#ifndef TIMEFRAME_H
#define TIMEFRAME_H

#include <iostream>
#include <chrono>

class Timeframe {
public:
    Timeframe(int startHour, int startMinute, int endHour, int endMinute);

    void setTimeframe(int startHour, int startMinute, int endHour, int endMinute);
    bool contains(const std::chrono::system_clock::time_point& time) const;


    //Off time member functions
    void addOffTime(const Timeframe& offTime); // New function to add "OFF" timeframes
    bool conflictsWithOffTimes() const; // New function to check for conflicts

    int getStartHour() const;
    int getStartMinute() const;
    int getEndHour() const;
    int getEndMinute() const;


private:
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point endTime;

    static std::vector<Timeframe> offTimes;     //list off times which can't be used for scheduling
};

#endif // TIMEFRAME_H