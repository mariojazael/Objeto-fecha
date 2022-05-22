#pragma once
#pragma warning 
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Fecha.h"
#include "Current_time.h"

class Inputmanager
{
public:
	int Control, opcion;
	int return_;
	char sub_menu_1_option;
	bool valid;
	Date date;
	Current_time current_time;
	Inputmanager();
	void set_sub_menu_1_option();
	void run();
	void Show_main_menu();
	void show_sub_menu_1();
	void evaluate_sub_menu_1_input();
	void set_option();
	void evaluate_main_menu_input();
	int choose_format();
};

