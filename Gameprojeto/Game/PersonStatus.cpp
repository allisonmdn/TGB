#include "PersonStatus.h"

PersonStatus::PersonStatus()
{
	this->healthBar = 100;   //HPMax
	this->staminaBar = 100;  //StaminaMAX

	this->strength = 1;		
	this->agility = 1;
	this->vitality = 1;
	this->intelligence = 1;

	this->atk = 0;
	this->atkM = 0;
	this->def = 1;
	this->defM = 1;	 

	this->powerUP = 1;

	this->healthp = 1;
	this->stamina = 1;

	attributes();
			
}

PersonStatus::~PersonStatus()
{

}

//void PersonStatus::attributes(int strength_, int vitality_, int intelligence_, int agility_, int powerUp_, int atk_, int atkM_, int def_, int defM_)
void PersonStatus::attributes()
{		
	/*this->strength = strength_;
	this->agility = agility_;
	this->vitality = vitality_;
	this->intelligence = intelligence_;			
	
	this->atk = atk_;
	this->atkM = atkM_;
	this->def = def_;
	this->defM = defM_;

	this->powerUP = powerUp_;*/

	//atk -= def; //Attacking
	//atkM -= defM;

	staminaBar += stamina;
	healthBar += healthp + (vitality * 5);

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

int PersonStatus::gethpMax()
{		
	return healthBar;
}

void PersonStatus::sethP(int healthp_)
{
	healthp = healthp_;		
}

void PersonStatus::setStaminaMax(int StaMax)
{		
	this->staminaBar = StaMax;
	
}

void PersonStatus::sethpMax(int hPMax)
{
	this->healthBar = hPMax;	
}

void PersonStatus::setStamina(int stamina_)
{		
	this->stamina = stamina_;
}

int PersonStatus::getStaminaMax()
{
	return staminaBar;
}

int PersonStatus::getStamina()
{
	return stamina;
}

int PersonStatus::getHp()
{
	return healthp;
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

void PersonStatus::drawPS()
{
	this->Profile();	
}

void PersonStatus::Profile()
{
		
}
