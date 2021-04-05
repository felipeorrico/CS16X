#pragma once

/******************************************************
** File: List_Program.h
** Author: Felipe Orrico Scognamiglio
** Date: 12/03/2019
******************************************************/

#ifndef List_Program_h
#define List_Program_h

#include "Linked_List.h"
#include <string>

class List_Program {
public:
	void run();
};

void loop_for_int(int& input, string message, int max, int min);
void loop_for_string(string& input, string message);
void loop_for_string2(string& input, string message);
void sort(Linked_List& l1, string ad);
#endif