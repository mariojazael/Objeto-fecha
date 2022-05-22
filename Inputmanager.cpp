	#include "Inputmanager.h"

	using namespace std;

	Inputmanager::Inputmanager() {
		Control = 10;
		opcion = NULL;
		valid = NULL;
		return_ = 1;
		sub_menu_1_option = NULL;
	}

	void Inputmanager::set_sub_menu_1_option() {
		try {
			cin >> sub_menu_1_option;
			if (sub_menu_1_option != '+' && sub_menu_1_option != '-' && sub_menu_1_option != 'e') {
				throw invalid_argument("La opcion ingresada es incorrecta, intentelo de nuevo");
			}
		}
		catch (invalid_argument& error) {
			system("cls");
			cerr << endl << error.what() << endl << endl;
			system("pause");
			system("cls");
			return_ = 4;
		}
	}

	void Inputmanager::run() {
		while (Control) {
			Show_main_menu();
			set_option();
			evaluate_main_menu_input();
		}
	}

	void Inputmanager::Show_main_menu() {
		system("cls");
		cout << "\nBienvenido a TODATE APP; digite el numero de la opcion que desea elegir:\n\n1. Mostrar la Fecha actual\n2. agregar una fecha y modificarla.\n\n";
	}

	void Inputmanager::show_sub_menu_1() {
		cout << "\n\n+ to Increase 1 day.\n- to Decrease 1 day.\ne to Exit to main menu.\n\n";
	}

	void Inputmanager::evaluate_sub_menu_1_input(){
		switch (sub_menu_1_option) {
			case '+':
				++date;
				break;
			case '-':
				--date;
				break;
			case 'e':
				return_ = 0;
				break;
		}
	}

	void Inputmanager::set_option() {
		cin >> opcion;
	}

	void Inputmanager::evaluate_main_menu_input() {
		switch (opcion) {
		case 1:
			current_time.set_current_time();
			current_time.option = choose_format();
			system("cls");
			cout <<"Current date: \n\n" << current_time << "\n\n";
			system("pause");
			break;
		case 2:
			if (date.introduce_date(valid)) { 
				date.option = choose_format();  
				while (return_) {
					system("cls");
					cout << "Current date: \n\n" << date << "\n\n";
					show_sub_menu_1();
					set_sub_menu_1_option();
					evaluate_sub_menu_1_input();
				}
				return_ = 1;
			}
			else { evaluate_main_menu_input(); }
			break;
		case 3:
			Control = 0;
			break;
		default:
			break;
		}
	}

	int Inputmanager::choose_format() {
		try {
			system("cls");
			cout << "Select the format (Enter the number of the option): " << endl << endl << "1. dd/mm/aaaa" << endl << "2. mm/dd/aaaa\n\n";
			cin >> opcion;
			if (opcion != 1 && opcion != 2) {
				throw invalid_argument("\n\nEl numero de opcion ingresado es incorrecto, intentelo de nuevo\n\n");
			}
			return opcion;
		}
		catch (invalid_argument& error) {
			system("cls");
			cerr << endl << error.what() << endl << endl;
			system("pause");
			system("cls");
			choose_format();
		}
	}
