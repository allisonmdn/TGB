#pragma once
#include "Personagem.h"
class Mage :
	public Personagem
{
public:
	Mage();
	~Mage();
	void attack() override;

};

