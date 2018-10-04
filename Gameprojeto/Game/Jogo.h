#include <iostream>	
#include "Personagem.h"
#include "Warrior.h"
#include "Mage.h"
#include "Thief.h"
//#include "LoadingResources.h"
#include "libUnicornio.h"
#include "Resources_Sound.h"
#include "ObjetoTileMap.h"

#pragma once
class Jogo : public Personagem

{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
	
private:
	Personagem * Class[3];
	TileMap mapa, mapa2;
	//fstream inORout;
	//ofstream outs;
	//ifstream ins;
	Sprite Btn;
	Resources_Sound LoadS;	
	
};
