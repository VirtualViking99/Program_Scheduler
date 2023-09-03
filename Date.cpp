#include "Date.h"
#include<iomanip>

Date::Date(int month, int day, int year) {
    setDate(month, day, year);
}


void Date::setDate(int month, int day, int year)
{
    struct std::tm timeinfo = {};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;

    date = std::chrono::system_clock::from_time_t(std::mktime(&timeinfo));
}

std::string Date::toString() const
{
    auto time = std::chrono::system_clock::to_time_t(date);
    struct std::tm timeinfo = *std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(&timeinfo, "%m/%d/%Y");
    return oss.str();
}

void Date::addToSchedule() {
    dateSchedule.insert(date);
}

void Date::removeFromSchedule() {
    if (!dateSchedule.empty()) {
        dateSchedule.erase(--dateSchedule.end());
    }
}

void Date::insertIntoSchedule() {
    dateSchedule.insert(date);
}

void Date::removeFromMiddleOfSchedule() {
    if (!dateSchedule.empty()) {
        auto middleIter = dateSchedule.begin();
        std::advance(middleIter, dateSchedule.size() / 2);
        dateSchedule.erase(middleIter);
    }
}