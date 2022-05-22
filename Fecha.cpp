#include "Fecha.h"

Date::Date() {
	Day = 25;
	Month = 04;
	Year = 2001;
	CorrectDay = false;
	option = NULL;
	dateInString = " ";
}

bool Date::setMonth() {
	try {
		cin >> Month;
		if (validate_Month()) {
			return true;
		}
	}
	catch(invalid_argument& error) {
		system("cls");
		cerr << endl << error.what() << endl << endl;
		system("pause");
		system("cls");
		return false;
	}
}

bool Date::setDay() {
	try {
		cin >> Day;
		if (validate_Day()) {
			return true;
		}
	}
	catch (invalid_argument& error) {
		system("cls");
		cerr << endl << error.what() << endl << endl;
		system("pause");
		system("cls");
		return false;
	}
}

bool Date::setYear() {
	try {
		cin >> Year;
		if (Year < 1900) {
			throw invalid_argument("El anio ingresado no es valido (solo se admiten anios mayores o iguales a 1900). intentalo de nuevo");
		}
		else{ return true; }
	}
	catch (invalid_argument& error) {
		system("cls");
		cerr << endl << error.what() << endl << endl;
		system("pause");
		system("cls");
		return false;
	}
}

int Date::getMonth() {
	return Month;
}

int Date::getDay() {
	return Day;
}

int Date::getYear() {
	return Year;
}

bool Date::validate_Day() {
	bool val = true;
	if (Day < 1 || Day > 31) {
		 val = false;
		 throw invalid_argument("El dia ingresado no es valido, intentalo de nuevo");
	}
	return val;
}

bool Date::validate_Month() {
	bool val = true;
	if (Month < 1 || Month > 12) {
		val = false;
		throw invalid_argument("El mes ingresado no es valido, intentalo de nuevo");
	}
	if (Day >= 29) {
		if (Day == 29 && Month == 2) { if(!is_leap_year()){ 
				val = false;
				throw invalid_argument("El mes ingresado no es valido debido a que el anio ingresado no es un anio bisiesto\ny en consecuencia Febrero no tiene 29 dias. Intentelo de nuevo"); }}
		if ((Day == 30 || Day == 31) && Month == 2){ 
			val = false;
			throw invalid_argument("El mes ingresado no es valido debido a que Febrero no tienen mas 29 dias. Intentalo de nuevo"); }
		if (Day == 31 && (Month == 4 || Month == 6 || Month == 9 || Month == 11)) { 
			val = false;
			throw invalid_argument("El mes ingresado no es valido debido a que dicho mes no tiene mas de 30 dias. Intentalo de nuevo"); }
	}
	return val;
}

bool Date::introduce_date(bool valid) {
	system("cls");
	cout << endl << "Introduce el anio: ";
	if (valid = setYear()) {
		cout << endl << "Introduce el dia: ";
		if (valid = setDay()) {
			cout << endl << "Introduce el mes: ";
			if (valid = setMonth()) {}
			else {
				system("cls");
				return valid = false;
			}
		}
		else{
			system("cls");
			return valid = false;
		}
	}
	else{
		system("cls");
		return valid = false;
	}
	return valid = true;
}

bool Date::evaluate_day_increase() {
	if (Day >= 28) {
		CorrectDay = evaluate_month_increase();
	}
	else {
		CorrectDay = false;
	}
	return CorrectDay;
}

bool Date::evaluate_month_increase() {
	if ((Month == 1 && Day == 31) || (Month == 3 && Day == 31) || (Month == 5 && Day == 31) || (Month == 7 && Day == 31) || (Month == 8 && Day == 31) || (Month == 10 && Day == 31) || (Month == 12 && Day == 31)) {
		CorrectDay = true;
	}
	if ((Month == 4 && Day == 30) || (Month == 6 && Day == 30) || (Month == 9 && Day == 30) || (Month == 11 && Day == 30)) {
		CorrectDay = true;
	}
	if (Month == 2 && Day == 28) {
		if (is_leap_year()) {}
		else { CorrectDay = true; }
	}
	if (Month == 2 && Day == 29) {
		CorrectDay = true;
	}
	return CorrectDay;
}

void Date::evaluate_year_increase() {
	if (Month == 13) {
		Month = 1;
		Year++;
	}
}

bool Date::evaluate_day_decrease() {
	if (Day == 1) { CorrectDay = evaluate_month_decrease(); }
	else { CorrectDay = false; }
	return CorrectDay;
}

bool Date::evaluate_month_decrease() {
	Month--;
	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) {
		Day = 31;
		CorrectDay = true;
	}
	if (Month == 4 || Month == 6 || Month == 9 || Month == 11) {
		Day = 30;
		CorrectDay = true;
	}
	if (Month == 2) {
		if (is_leap_year()) { Day = 29; }
		else { Day = 28; }
		CorrectDay = true;
	}
	if (Month == 0) {
		Day = 31;
		CorrectDay = true;
	}
	return CorrectDay;
}

void Date::evaluate_year_decrease() {
	if (Month == 0) {
		Month = 12;
		Year--;
	}
}

bool Date::is_leap_year() {
	bool leap_year;
	if (Year % 4 == 0) {
		leap_year = true;
		if (Year % 100 == 0 && Year % 400 != 0) { leap_year = false; }
		else {}
	}
	else {
		leap_year = false;
	}
	return leap_year;
}

void Date::print_date(int option) {
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


