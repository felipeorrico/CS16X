/******************************************************
** File: Linked_List.cpp
** Author: Felipe Orrico Scognamiglio
** Date: 12/03/2019
******************************************************/

#include "Linked_List.h"
#include "Node.h"
#include <iostream>

using namespace std;

/*********************************************************************
** Function: contructor
** Description: contructor for the linked list class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Linked_List::Linked_List()
{
	length = 0;
	head = nullptr;
}

/*********************************************************************
** Function: destructor
** Description: destructor for the linked list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Linked_List::~Linked_List()
{
	Node* next = head;
	Node* cur = nullptr;
	while (next != nullptr) {
		cur = next;
		next = next->next;
		delete cur;
	}
	delete next;
}

/*********************************************************************
** Function: get_length
** Description: gets length
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns length
*********************************************************************/
int Linked_List::get_length()
{
	return length;
}

/*********************************************************************
** Function: print
** Description: prints the linked list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Linked_List::print()
{
	cout << "Current Size: " << length << endl;
	Node* head = this->head;
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	delete head;
}

/*********************************************************************
** Function: clear
** Description: deletes all the data of the list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Linked_List::clear()
{
	Node* next = head;
	Node* cur = nullptr;
	while (next != nullptr) {
		cur = next;
		next = next->next;
		delete cur;
	}
	length = 0;
}

/*********************************************************************
** Function: push_front
** Description: adds the value to the front of the list and shifts everything else
** Parameters: value
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
unsigned int Linked_List::push_front(int val) //working
{
	Node* node = new Node();
	node->val = val;
	node->next = this->head;
	this->head = node;
	this->length++;
	return length;
}

/*********************************************************************
** Function: push_back
** Description: adds the value to the end of the list
** Parameters: value
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
unsigned int Linked_List::push_back(int val) //working
{
	Node* node = this->head;
	if (node == nullptr) {
		node = new Node;
		this->head = node;
	}
	else {
		while (node->next != nullptr) {
			node = node->next;
		}
		node->next = new Node;
		node = node->next;
	}
	node->val = val;
	node->next = nullptr;
	this->length++;
}

/*********************************************************************
** Function: insert
** Description: inserts the value on the desired index
** Parameters: value and index
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
unsigned int Linked_List::insert(int val, unsigned int index)
{
	Node* previous,* current = head, * temp;

	for (int i = 1; i < index; i++)
	{
		previous = current;
		current = current->next;
	}
	temp->val = val;
	previous->next = temp;
	temp->next = current;
	this->length++;
	return length;
}

/*********************************************************************
** Function: sort_ascending
** Description: calls the merge sort function to sort the list
** Parameters:none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Linked_List::sort_ascending()
{
	MergeSort(&head);
}

/*********************************************************************
** Function: sort_descending
** Description: calls the merge sort function to sort the list, then calls the reverse function to invert the values of the list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Linked_List::sort_descending()
{
	MergeSort(&head);
	reverse();
}

/*********************************************************************
** Function: Merge
** Description: separates the list in two parts and sorts them
** Parameters: the initial thow halfs of the list
** Pre-Conditions: requires list to be divided
** Post-Conditions: calls itself until not divisible anymore
*********************************************************************/
Node* Linked_List::Merge(Node* Half1, Node* Half2)
{
	Node* thalf1, *thalf2, *temp; //temporary pointers for each half and the final list

	if (Half1 == nullptr) //checks if the node is valid, if not it will return the other half
		return Half2;

	if (Half2 == nullptr) //if the first hlf exists bu second does not, will return first half.
		return Half1;

	thalf1 = Half1; //sets temporary half to first half

	while (Half2 != nullptr) //goes through second half until there is no next value in it.
	{
		thalf2 = Half2; 
		Half2 = Half2->next;
		thalf2->next = nullptr;
		if (Half1->val > thalf2->val) //compares the values between the halfs and sets them accordingly
		{
			thalf2->next = Half1;
			Half1 = thalf2;
			thalf1 = Half1;
			continue;
		}
		//loops back to here
		again:if (thalf1->next == nullptr)  //if the first half is not a nullptr, then it will send that value to the second half and go to the next value in the list
		{
			thalf1->next = thalf2;
			thalf1 = thalf1->next;
		}
		else if ((thalf1->next)->val <= thalf2->val)
		{
			thalf1 = thalf1->next;
			goto again; //introduces small goto loop that will happen if the values are equal or less than the other
		}
		else
		{
			temp = thalf1->next; //sets the temporary half to the next value of the first half
			thalf1->next = thalf2; //sets the next value of the first half to the value of the first value of the second half
			thalf2->next = temp; //sets then the value of the second value of the second half to the temporary value set before on the above statement
		}
	}
	return Half1;
}

/*********************************************************************
** Function: Merge Sort
** Description: gets the pointer to the first node and separates the initial two halfs to be sent to the merge function
** Parameters: node head
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Linked_List::MergeSort(Node** head)
{
	Node* first; //node to separate first half
	Node* second; //node to separate second half
	Node* temp; //temporaty node to store second half after first half is split
	first = *head; //point the head of the first node into the first half
	temp = *head; //store array so can then take first half off

	if (first == nullptr || first->next == nullptr)
	{
		return; //checks if list is valid
	}
	else
	{
		while (first->next != nullptr)
		{
			first = first->next;//setting pointers to the first half of the list
			if (first->next != nullptr)
			{
				temp = temp->next; //setting the temp pointers for the second half of the list
				first = first->next; 
			}
		}
		second = temp->next; //setting second half equal to temporary half
		temp->next = nullptr; // "deleting" temporary half
		first = *head; //setting the first half to the head of the list
	}
	MergeSort(&first); //further separate first half
	MergeSort(&second);   //further separate second half
	*head = Merge(first, second); //merges both halfs together
}

/*********************************************************************
** Function: count_prime
** Description: counts and returns the number of prime numbers in the list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Linked_List::countPrime() //check this function, may be counting 1's as prime
{
	Node* head = this->head;
	int primes = 0;
	while (head) {
		bool isPrime = true;
		for (int j = 2; j <= head->val / 2; ++j)
		{ 
			if (head->val % j == 0) //checks if the number is divisible by any number besides itself and 1.
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime && head->val != 1) {
			primes++;
		}
		head = head->next;
	}
	return primes;
}

/*********************************************************************
** Function: reverse
** Description: reverses the order of the list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Linked_List::reverse() //change pointers to invert the order of the list
{
	Node* current = head;
	Node* prev = nullptr, * next = nullptr;

	while (current != nullptr) { //this will invert the order of the pointers in the list this way flipping it.
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}
	head = prev;
}
