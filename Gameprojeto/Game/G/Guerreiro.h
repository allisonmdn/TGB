#include <iostream>
#include <string>
#include <conio.h>
#include "Personagem.h"


#pragma once
class Guerreiro: public Personagem
{
public:
	Guerreiro();
	~Guerreiro();
	bool walk();
	bool talk();
	virtual bool block();
	virtual bool attack();
	int getStrength();
	int getAgility();
	int getVitality();
	int getIntelligence();
	int getDexterity();
	int getLucky();
	int getHp();
	char key;
	void Update();	

protected:
	int strength, agility, vitality, intelligence, dexterity, lucky, hp;
	
};



//set eq. * atrib / def
//set eq. * atrib / atk (formula)