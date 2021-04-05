/*********************************************************************
** Program Filename: Sea_Lion.h
** Author: Felipe Orrico Scognamiglio
** Date: 11/07/19
** Description: Definition of Sea Lion Class
*********************************************************************/

#ifndef lion_h
#define lion_h
#include "Animal.h"

class Slion : public Animal {
private:
	float bonus_multiplier;

public:
	void set_bonus(float);
	float get_bonus();
	Slion();
	~Slion();
};

#endif