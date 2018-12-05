#include <iostream>	
#include "Personagem.h"
#include "Knight.h"
#include "Mage.h"
#include "Thief.h"
//#include "LoadingResources.h"
#include "libUnicornio.h"
#include "Resources_Sound.h"
#include "ObjetoTileMap.h"
#include "Menu.h"
#include "Selecao.h"

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
	//TileMap mapa, mapa2;
	//fstream inORout;
	//ofstream outs;
	//ifstream ins;
	Sprite treasure;
	Sprite Btn;
	Resources_Sound LoadS;
	Menu menuz;
	Selecao selec;
	
	
};
