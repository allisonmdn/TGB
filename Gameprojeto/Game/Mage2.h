#pragma once
#include "Personagem2.h"
class Mage2: public Personagem2
{
public:
	Mage2();
	~Mage2();
	void attack() override;
protected:

	//Resources_Sound Sounds;
};

