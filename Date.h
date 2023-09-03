#pragma once
#ifndef DATE_H

#define DATE_H

#include<iostream>
#include<chrono>
#include<set>

class Date
{
public:
	Date(int month, int day, int year);

	void setDate(int month, int day, int year);
	std::string toString() const;

	void addToSchedule();
	void removeFromSchedule();
	void insertIntoSchedule();
	void removeFromMiddleOfSchedule();

private:
	std::chrono::system_clock::time_point date;

	std::multiset<std::chrono::system_clock::time_point> dateSchedule; // Multiset to store ordered dates
};


#endif // !DATE_H
