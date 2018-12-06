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

	this->healthp = 50;
	this->stamina = 1;
	
}

PersonStatus::~PersonStatus()
{
}

void PersonStatus::attributes()
{
	//atk -= def; Attacking
	//atkM -= defM;
	healthBar += healthp +(vitality * 5);
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

int PersonStatus::gethpMax()
{			
	return healthBar;
}

int PersonStatus::getStaminaMax()
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

void PersonStatus::drawPS()
{
	this->Profile();	
}

void PersonStatus::Profile()
{
	//HP LIFE POINTS

	lifep.setFonte("fonte profile");	
	lifep.setCor(0, 0, 0, true);
	lifep.setString(Hp_v + std::to_string(gethpMax()));
	lifep.setAlinhamento(TEXTO_ALINHADO_A_DIREITA);
	lifep.setEspacamentoLinhas(1.5f);

	//STAMINA POINTS

	sta.setFonte("fonte profile");
	sta.setCor(0, 0, 0, true);
	sta.setString(stamina_v + std::to_string(getStaminaMax()));
	sta.setAlinhamento(TEXTO_ALINHADO_A_DIREITA);
	sta.setEspacamentoLinhas(1.5f);


	//PLAYER PROFILE

	Texto_.setFonte("fonte profile");
	Texto_.setCor(0, 0, 0, true);
	Texto_.setString(TextoTeste);
	Texto_.setAlinhamento(TEXTO_ALINHADO_A_DIREITA);
	Texto_.setEspacamentoLinhas(1.5f); 
		

	//DRAW TEXT

	this->Texto_.desenhar(50, 40);
	this->lifep.desenhar(50, 70);
	this->sta.desenhar(150, 70);
	
}
