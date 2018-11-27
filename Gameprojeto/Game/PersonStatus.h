#include <iostream>

class PersonStatus
{
public:
	PersonStatus();
	~PersonStatus();
	float healthBar;
	int staminaBar; 
	void attributes(); // Method of attributes to added to a person.
protected:
	float speed; //Moviment.
	int stregth, vitality, intelligence, agility; // attributes variables.
	int stamina; //stamina var.

};