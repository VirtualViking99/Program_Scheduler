#ifndef EVENT_H
#define EVENT_H
#include<iostream>
#include<vector>
#include <string>

#include "Timeframe.h" // Include the Timeframe header

class Event {
public:
    Event(const std::string& name, const std::string& place);

    const std::string& getName() const;
    const std::string& getPlace() const;
    const Timeframe& getTimeframe() const; // Add a getter for the timeframe

    void modifyEvent(const std::string& newName, const std::string& newPlace);



    void addParticipant(const std::string& participant);
    const std::vector<std::string>& getParticipants() const;
    std::string getParticipantsAsString() const; // Add this function


private:
    std::string eventName;
    std::string eventPlace;

    Timeframe eventTimeframe; // Add a Timeframe member


    std::vector<std::string> participants;
};

#endif // EVENT_H
