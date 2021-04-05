#pragma once
/******************************************************
** File: Node.h
** Author: Felipe Orrico Scognamiglio
** Date: 12/03/2019
******************************************************/
#ifndef Node_H
#define Node_H

using namespace std;

class Node {
public:
	int val;    // the value that this Node stores
	Node* next; // a pointer to the next Node in the list
	// you can add constructors or other functionality if you find it useful or necessary
};

#endif
