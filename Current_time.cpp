#include "Current_time.h"

Current_time::Current_time() {
	current_time = time(0);
	time_ = localtime(&current_time);
	Day = NULL;
	Month = NULL;
	Year = NULL;
	option = NULL;
	dateInString = " ";
}

void Current_time::setDay() {
	Day = time_->tm_mday;
}

void Current_time::setMonth() {
	Month = time_->tm_mon + 1;
}

void Current_time::setYear() {
	Year = time_->tm_year + 1900;
}

int Current_time::getDay() {
	return Day;
}

int Current_time::getMonth() {
	return Month;
}

int Current_time::getYear() {
	return Year;
}

void Current_time::set_current_time() {
	setDay();
	setMonth();
	setYear();
}

void Current_time::print_date(int option) {
	switch (option) {
	case 1:
		system("cls");
		cout << getDay() << " / " << getMonth() << " / " << getYear() << endl << endl;
		system("pause");
		break;
	case 2:
		system("cls");
		cout << getMonth() << " / " << getDay() << " / " << getYear() << endl << endl;
		system("pause");
		break;
	}
}
