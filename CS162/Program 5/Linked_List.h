#pragma once

/******************************************************
** File: Linked_List.h
** Author: Felipe Orrico Scognamiglio
** Date: 12/03/2019
******************************************************/

#include "Node.h"

#ifndef Linked_H
#define Linked_H

using namespace std;

class Linked_List {
private:
	unsigned int length;
	Node* head;
public:
	Linked_List();
	~Linked_List();
	int get_length();

	void print();
	void clear(); 
	unsigned int push_front(int);
	unsigned int push_back(int);
	unsigned int insert(int val, unsigned int index); 
	void sort_ascending(); 
	void sort_descending();
	
	void reverse();
	Node* Merge(Node*, Node*);
	void MergeSort(Node** head);
	int countPrime();
};

#endif // !Linked_H