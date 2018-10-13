#include "Personagem.h"

#pragma once
class Personagem2: virtual public Personagem
{
public:
	Personagem2();
	~Personagem2();
	bool walk() override;
};

