#include "Event.h"



Event::Event(const std::string& name, const std::string& place)
    : eventName(name), eventPlace(place) {}

const std::string& Event::getName() const {
    return eventName;
}



const std::string& Event::getPlace() const {
    return eventPlace;
}

const Timeframe& Event::getTimeframe() const {
    return eventTimeframe;
}


void Event::modifyEvent(const std::string& newName, const std::string& newPlace) {
    eventName = newName;
    eventPlace = newPlace;
}

void Event::addParticipant(const std::string& participant)
{
    participants.push_back(participant);
}

const std::vector<std::string>& Event::getParticipants() const {
    return participants;
}

std::string Event::getParticipantsAsString() const {
    std::string participantsString;
    for (size_t i = 0; i < participants.size(); ++i) {
        participantsString += participants[i];
        if (i < participants.size() - 1) {
            participantsString += ", ";
        }
    }
    return participantsString;
}