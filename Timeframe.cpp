#include "Timeframe.h"


std::vector<Timeframe> Timeframe::offTimes;

Timeframe::Timeframe(int startHour, int startMinute, int endHour, int endMinute) {
    setTimeframe(startHour, startMinute, endHour, endMinute);
}

void Timeframe::setTimeframe(int startHour, int startMinute, int endHour, int endMinute) {
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);
    struct std::tm timeinfo = *std::localtime(&now_time);

    timeinfo.tm_hour = startHour;
    timeinfo.tm_min = startMinute;
    startTime = std::chrono::system_clock::from_time_t(std::mktime(&timeinfo));

    timeinfo.tm_hour = endHour;
    timeinfo.tm_min = endMinute;
    endTime = std::chrono::system_clock::from_time_t(std::mktime(&timeinfo));
}

bool Timeframe::contains(const std::chrono::system_clock::time_point& time) const {
    return (time >= startTime && time <= endTime);
}

//Add off times

void Timeframe::addOffTime(const Timeframe& offTime) {
    offTimes.push_back(offTime);
}

bool Timeframe::conflictsWithOffTimes() const {
    for (const auto& offTime : offTimes) {
        if (startTime < offTime.endTime && endTime > offTime.startTime) {
            return true;
        }
    }
    return false;
}

int Timeframe::getStartHour() const {
    auto time = std::chrono::system_clock::to_time_t(startTime);
    struct std::tm timeinfo = *std::localtime(&time);
    return timeinfo.tm_hour;
}

int Timeframe::getStartMinute() const {
    auto time = std::chrono::system_clock::to_time_t(startTime);
    struct std::tm timeinfo = *std::localtime(&time);
    return timeinfo.tm_min;
}

int Timeframe::getEndHour() const {
    auto time = std::chrono::system_clock::to_time_t(endTime);
    struct std::tm timeinfo = *std::localtime(&time);
    return timeinfo.tm_hour;
}

int Timeframe::getEndMinute() const {
    auto time = std::chrono::system_clock::to_time_t(endTime);
    struct std::tm timeinfo = *std::localtime(&time);
    return timeinfo.tm_min;
}