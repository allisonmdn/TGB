#include "PersonStatus.h"

PersonStatus::PersonStatus()
{
	this->healthBar = 0;   //HPMax
	this->staminaBar = 0;  //StaminaMAX
	this->strength = 0;		
	this->agility = 0;
	this->vitality = 0;
	this->intelligence = 0;
	this->atk = 0;
	this->atkM = 0;
	this->def = 0;
	this->defM = 0;
	this->stamina = 0;
	this->powerUP = 0;
	
}

PersonStatus::~PersonStatus()
{
}

void PersonStatus::attributes()
{
	//atk -= def; Attacking
	//atkM -= defM;
	healthBar += (vitality * 5);
	staminaBar += stamina;
	
	
}

void PersonStatus::DamageTaken()
{
	
	if (atk > 0)
	{
		healthBar -= (atk - def);
	}
	else
	{
		healthBar -= (atkM - defM);
	}
	staminaBar -= (atk + atkM * 0.5);
	
}

float PersonStatus::gethpMax()
{
	return healthBar;
}

float PersonStatus::getStaminaMax()
{
	return staminaBar;
}

int PersonStatus::getStrength()
{
	return strength;
}

int PersonStatus::getAgility()
{
	return agility;
}

int PersonStatus::getVitality()
{
	return vitality;
}

int PersonStatus::getIntelligence()
{
	return intelligence;
}
