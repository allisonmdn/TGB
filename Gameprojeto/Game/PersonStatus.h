#include <iostream>
#include "Personagem.h"
#include "Knight.h"
#include "Thief.h"
#include "Mage.h"

class PersonStatus
{
public:
	PersonStatus();
	~PersonStatus();
	float healthBar;
	int staminaBar; 
	void attributes(); // Method of attributes to added to a person.
	void DamageTaken();
	float gethpMax();
	float getStaminaMax();
	int getStrength();
	int getAgility();
	int getVitality();
	int getIntelligence();
	
protected:
	
	int strength, vitality, intelligence, agility; // attributes variables.
	int powerUP;
	int atk, atkM; //Atk
	int def, defM;
	float stamina; //stamina var.

};