#pragma once
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

class Current_time{
private:
	int Day, Month, Year;
	time_t current_time;
	tm* time_;
	string dateInString;
public:
	int option;
	Current_time();
	void setDay();
	void setMonth();
	void setYear();
	int getDay();
	int getMonth();
	int getYear();
	void set_current_time();
	void print_date(int);
	operator char const* () {
		ostringstream formattedDate;
		if (option == 1) {
			formattedDate << Day << " / " << Month << " / " << Year;
		}
		else {
			formattedDate << Month << " / " << Day << " / " << Year;
		}
		dateInString = formattedDate.str();
		return dateInString.c_str();
	}
};

