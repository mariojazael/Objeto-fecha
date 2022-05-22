#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Date
{
private:
	int Month, Day, Year;
	string dateInString;
	bool CorrectDay = false;
public:
	int option;
	Date();
	Date(int inDay, int inMonth, int inYear, bool inCorrectDay) : Day(inDay), Month(inMonth), Year(inYear), CorrectDay(inCorrectDay) {};
	bool setMonth();
	bool setDay();
	bool setYear();
	int getMonth();
	int getDay();
	int getYear();
	bool validate_Day();
	bool validate_Month();
	bool introduce_date(bool);
	bool evaluate_day_increase();
	bool evaluate_month_increase();
	void evaluate_year_increase();
	bool evaluate_day_decrease();
	bool evaluate_month_decrease();
	void evaluate_year_decrease();
	bool is_leap_year();
	void print_date(int);
	Date& operator ++() {
		if (evaluate_day_increase()) {
			Day = 1;
			++Month; 
		}
		else { ++Day; }
		evaluate_year_increase();
		return *this;
	}
	Date& operator --() {
		if (evaluate_day_decrease()) {
			evaluate_year_decrease();
		}
		else { --Day; }
		return *this;
	}
	Date operator ++(int) {
		Date date_1 (25, 04, 2001, false);
		if (evaluate_day_increase()) {
			Day = 1;
			Month++;
		}
		else { Day++; }
		evaluate_year_increase();
		return date_1;
	}
	Date operator --(int) {
		Date date_1(25, 04, 2001, false);
		if (evaluate_day_decrease()) {
			evaluate_year_decrease();
		}
		else { Day--; }
		return date_1;
	}
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

