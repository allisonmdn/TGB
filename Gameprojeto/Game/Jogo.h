#include <iostream>	
#include "libUnicornio.h"
#include "Personagem.h"
#include "Warrior.h"


#pragma once
class Jogo: public Personagem
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();	

private:
	Personagem * Class[3];
	TileMap mapa;
	
	
};

